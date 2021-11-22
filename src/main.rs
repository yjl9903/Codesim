#[macro_use]
extern crate lazy_static;

extern crate clang;

mod parse;

use parse::Parser;
use std::path::PathBuf;
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
    println!("Diff: {:?} {:?}", options.code1, options.code2);
  }

  let parser = Parser::new();

  let tu = parser.parse(options.code1.into());

  // Get the structs in this translation unit
  let structs = tu
    .get_entity()
    .get_children()
    .into_iter()
    .filter(|e| e.get_kind() == clang::EntityKind::StructDecl)
    .collect::<Vec<_>>();

  // Print information about the structs
  for struct_ in structs {
    let type_ = struct_.get_type().unwrap();
    let size = type_.get_sizeof().unwrap();
    println!(
      "struct: {:?} (size: {} bytes)",
      struct_.get_name().unwrap(),
      size
    );

    for field in struct_.get_children() {
      if let Some(name) = field.get_name() {
        if let Ok(offset) = type_.get_offsetof(&name) {
          println!("  field: {:?} (offset: {} bits)", name, offset);
        } else {
          println!("  field: {:?}", name);
        }
      } else {

      }
    }
  }
}
