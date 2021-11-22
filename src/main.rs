mod loader;

#[macro_use]
extern crate lazy_static;

use std::path::PathBuf;
use loader::Loader;
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

  let ld1 = Loader::new(&options.code1, options.verbose);
  let ld2 = Loader::new(&options.code2, options.verbose);

  ld1.compile();
  ld2.compile();

  ld1.symbol_table();
  ld2.symbol_table();
}
