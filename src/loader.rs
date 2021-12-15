use std::{
  collections::{BTreeMap, HashMap, HashSet},
  path::PathBuf,
};

use regex::Regex;
use tempfile::NamedTempFile;

lazy_static! {
  static ref SYMTABLE_BLACKLIST: HashSet<&'static str> = {
    let mut set = HashSet::new();
    set.insert("__mh_execute_header");
    set.insert("___clang_call_terminate");
    set.insert("_start");
    set.insert("_init");
    set.insert("_fini");
    set.insert("__libc_csu_fini");
    set.insert("__libc_csu_init");
    set.insert("_dl_relocate_static_pie");
    set.insert("frame_dummy");
    set.insert("register_tm_clones");
    set.insert("deregister_tm_clones");
    set.insert("__do_global_dtors_aux");
    set
  };
  static ref CODE_REGEX: Regex = Regex::new(r"([0-9a-f][0-9a-f] )+").unwrap();
}

pub type DumpResult = BTreeMap<u64, Vec<u64>>;

pub struct Loader {
  pub source: PathBuf,
  elf_temp: NamedTempFile,
  skip_compile: bool,
  verbose: bool,
}

impl Loader {
  pub fn new(file: &PathBuf, skip_compile: bool, verbose: bool) -> Self {
    let elf_temp = NamedTempFile::new().unwrap();
    Loader {
      source: file.clone(),
      elf_temp,
      skip_compile,
      verbose,
    }
  }

  fn elf(&self) -> PathBuf {
    if self.skip_compile {
      self.source.clone()
    } else {
      self.elf_temp.path().to_path_buf()
    }
  }

  pub fn compile(&self) -> Result<(), String> {
    if self.skip_compile {
      return Ok(());
    }

    if self.verbose {
      println!("$ clang++ --std=c++17 -pedantic -O2 {:?}", self.source);
    }

    let res = std::process::Command::new("clang++")
      .arg("--std=c++17")
      .arg("-pedantic")
      .arg("-O2")
      .arg(&self.source)
      .arg("-o")
      .arg(self.elf_temp.path())
      .output();

    if let Ok(cmd) = res {
      if !cmd.status.success() {
        let stderr = String::from_utf8_lossy(&cmd.stderr).into_owned();
        return Err(stderr);
      }
    } else {
      let msg = format!("Fail to compile {:?}", self.source);
      return Err(msg);
    }

    if self.verbose {
      println!("Compile output: {:?}", self.elf_temp.path());
    }

    Ok(())
  }

  pub fn symbol_table(&self) -> Vec<(String, u64)> {
    if self.verbose {
      println!("\n$ nm --demangle --defined-only -P {:?}", self.elf());
    }

    let cmd = std::process::Command::new("nm")
      .arg("--demangle")
      .arg("--defined-only")
      .arg("-P")
      .arg(self.elf())
      .output()
      .expect("Fail to run nm");

    let content = String::from_utf8_lossy(&cmd.stdout).into_owned();

    let mut symbols = Vec::new();
    for line in content.trim_end().split("\n") {
      let line: Vec<&str> = if line.contains(" T ") {
        line.trim_end().split(" T ").collect()
      } else if line.contains(" t ") {
        line.trim_end().split(" t ").collect()
      } else {
        continue;
      };
      let func = line.get(0).unwrap().to_string();
      let global_sub = format!(
        "_GLOBAL__sub_I_{}",
        self.source.file_name().unwrap().to_string_lossy()
      );
      if SYMTABLE_BLACKLIST.contains(&func[..])
        || func.find("std::").is_some()
        || func.starts_with(&global_sub)
      {
        continue;
      }
      let address = line.get(1).unwrap().split(" ").next().unwrap().to_string();
      let address = u64::from_str_radix(&address, 16).unwrap();
      if self.verbose {
        println!("Func: {} -> {:#11x}", &func, &address);
      }
      symbols.push((func, address));
    }

    if symbols.is_empty() {
      eprintln!(
        "No symbol found in {:?}, please check your code or elf.",
        self.elf()
      );
      panic!();
    }

    symbols
  }

  pub fn dump(&self, symbols: Vec<(String, u64)>) -> DumpResult {
    if self.verbose {
      println!("\n$ objdump -d {:?}", self.elf());
    }

    let func_address = symbols
      .into_iter()
      .map(|(func, addr)| (addr, func))
      .collect::<HashMap<u64, String>>();

    let cmd = std::process::Command::new("objdump")
      .arg("-d")
      .arg(self.elf())
      .output()
      .expect("Fail to run objdump");

    fn parse_address(line: &str) -> Option<u64> {
      if let Some(address) = line.split(":").next() {
        let address = address.trim();
        if let Ok(address) = u64::from_str_radix(address, 16) {
          Some(address)
        } else {
          None
        }
      } else {
        None
      }
    }

    fn parse_code(line: &str) -> Option<u64> {
      if let Some(capture) = CODE_REGEX.captures(line) {
        if let Some(matched) = capture.get(0) {
          let code = matched
            .as_str()
            .chars()
            .filter(|c| !c.is_whitespace())
            .collect::<String>();
          u64::from_str_radix(&code, 16).map_or(None, |c| Some(c))
        } else {
          None
        }
      } else {
        None
      }
    }

    let mut map = BTreeMap::new();
    let mut i = 0 as usize;
    let content = String::from_utf8_lossy(&cmd.stdout).into_owned();
    let content = content.trim().split("\n").collect::<Vec<&str>>();

    while i < content.len() {
      let line = content[i];
      if let Some(address) = parse_address(line) {
        if func_address.contains_key(&address) {
          let mut code = Vec::new();
          while i < content.len() {
            if let Some(_) = parse_address(content[i]) {
              if let Some(cmd) = parse_code(content[i]) {
                code.push(cmd);
                i = i + 1;
              } else {
                break;
              }
            } else {
              break;
            }
          }

          if self.verbose {
            let func = func_address.get(&address).unwrap();
            println!(
              "Found func: {:?} -> {:#11x} (size: {:?})",
              func,
              address,
              code.len()
            );
          }

          map.insert(address, code);
        } else {
          i = i + 1;
        }
      } else {
        i = i + 1;
      }
    }

    if map.is_empty() {
      eprintln!(
        "No symbol found in {:?}, please check your code or elf.",
        self.elf()
      );
      panic!();
    }

    map
  }
}
