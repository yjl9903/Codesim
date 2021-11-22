use std::{collections::HashSet, path::PathBuf};

use tempfile::NamedTempFile;

lazy_static! {
  static ref SYMTABLE_BLACKLIST: HashSet<&'static str> = {
    let mut set = HashSet::new();
    set.insert("__mh_execute_header");
    set.insert("___clang_call_terminate");
    set
  };
}

pub struct Loader {
  source: PathBuf,
  elf_temp: NamedTempFile,
  verbose: bool,
}

impl Loader {
  pub fn new(file: &PathBuf, verbose: bool) -> Self {
    let elf_temp = NamedTempFile::new().unwrap();
    Loader {
      source: file.clone(),
      elf_temp,
      verbose,
    }
  }

  pub fn compile(&self) {
    std::process::Command::new("clang++")
      .arg("--std=c++17")
      .arg("-pedantic")
      .arg("-O2")
      .arg(&self.source)
      .arg("-o")
      .arg(self.elf_temp.path())
      .output()
      .expect("Failed to compile source file");

    if self.verbose {
      println!("Compile output of {:?} -> {:?}", &self.source, self.elf_temp.path());
    }
  }

  pub fn symbol_table(&self) -> Vec<(String, String)> {
    if self.verbose {
      println!("nm {:?}", self.source);
    }

    let cmd = std::process::Command::new("nm")
      .arg("--demangle")
      .arg("--defined-only")
      // .arg("-g")
      .arg("-P")
      .arg(self.elf_temp.path())
      .output()
      .expect("Fail to run nm");

    let content = String::from_utf8_lossy(&cmd.stdout).into_owned();

    let mut symbols: Vec<(String, String)> = Vec::new();
    for line in content.trim_end().split("\n") {
      let line: Vec<&str> = if line.contains(" T ") {
        line.trim_end().split(" T ").collect()
      } else if line.contains(" t ") {
        line.trim_end().split(" t ").collect()
      } else {
        continue;
      };
      let func = line.get(0).unwrap().to_string();
      if SYMTABLE_BLACKLIST.contains(&func[..]) || func.starts_with("std::") {
        continue;
      }
      let address = line.get(1).unwrap().split(" ").next().unwrap().to_string();
      if self.verbose {
        println!("{} -> {}", &func, &address);
      }
      symbols.push((func, address));
    }

    symbols
  }
}
