#[macro_use]
extern crate lazy_static;

use std::{
  collections::HashSet,
  path::{Path, PathBuf},
};
use structopt::StructOpt;

#[derive(StructOpt)]
#[structopt(name = "codesim", about = "Diff two single C++ code")]
struct CliOption {
  #[structopt(short = "-v", long = "--verbose", help = "verbose")]
  verbose: bool,

  #[structopt(parse(from_os_str), help = "source code")]
  code1: PathBuf,

  #[structopt(parse(from_os_str), help = "target code")]
  code2: PathBuf,
}

fn main() {
  let options = CliOption::from_args();
  if options.verbose {
    println!("Diff: {:?} v.s. {:?}", options.code1, options.code2);
  }

  let c1 = compile(&options.code1);
  if options.verbose {
    println!("Compile output of {:?} -> {:?}", &options.code1, &c1);
  }

  let c2 = compile(&options.code2);
  if options.verbose {
    println!("Compile output of {:?} -> {:?}", &options.code2, &c2);
  }

  read_symtable(c1.path(), options.verbose);

  read_symtable(c2.path(), options.verbose);
}

fn compile(file: &PathBuf) -> tempfile::NamedTempFile {
  let temp = tempfile::NamedTempFile::new().unwrap();

  std::process::Command::new("clang++")
    .arg("--std=c++17")
    .arg("-pedantic")
    .arg("-O2")
    .arg(file)
    .arg("-o")
    .arg(temp.path())
    .output()
    .expect("Failed to compile source file");

  temp
}

lazy_static! {
  static ref SYMTABLE_BLACKLIST: HashSet<&'static str> = {
    let mut set = HashSet::new();
    set.insert("__mh_execute_header");
    set
  };
}

fn read_symtable(file: &Path, verbose: bool) -> Vec<(String, String)> {
  if verbose {
    println!("nm {:?}", file);
  }

  let cmd = std::process::Command::new("nm")
    .arg("--defined-only")
    .arg("-g")
    .arg("-P")
    .arg("--demangle")
    .arg("-S")
    .arg(file)
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
    if SYMTABLE_BLACKLIST.contains(&func[..]) {
      continue;
    }
    let address = line.get(1).unwrap().split(" ").next().unwrap().to_string();
    if verbose {
      println!("{} -> {}", &func, &address);
    }
    symbols.push((func, address));
  }

  symbols
}
