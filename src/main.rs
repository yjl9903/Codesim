mod flow;
mod loader;
mod solver;

#[macro_use]
extern crate lazy_static;

use loader::Loader;
use solver::Solver;
use std::path::PathBuf;
use structopt::StructOpt;

const OMEGA: f64 = 1.5;
const ALPHA: f64 = 2.0;
const BETA: f64 = 0.5;

#[derive(StructOpt)]
#[structopt(name = "codesim", about = "Diff two single C++ code")]
struct CliOption {
  #[structopt(short = "-v", long = "--verbose", help = "verbose")]
  verbose: bool,

  #[structopt(long = "--skip-compile", help = "skip compile")]
  skip_comiple: bool,

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

  if options.verbose {
    println!();
    println!("--- Load code1: {:?} ---", &options.code1);
  }
  let ld1 = Loader::new(&options.code1, options.skip_comiple, options.verbose);
  ld1.compile();
  let sym1 = ld1.symbol_table();
  let func1 = ld1.dump(sym1);

  if options.verbose {
    println!();
    println!("--- Load code2: {:?} ---", &options.code2);
  }
  let ld2 = Loader::new(&options.code2, options.skip_comiple, options.verbose);
  ld2.compile();
  let sym2 = ld2.symbol_table();
  let func2 = ld2.dump(sym2);

  let sum_func1 = func1.iter().map(|(_, body)| body.len()).sum::<usize>();

  // Run diff
  let solver = Solver::new(func1, func2, options.verbose);
  if options.verbose {
    println!();
    println!("--- Calc function similarity ---");
  }
  let builder = solver.construct(OMEGA, ALPHA, BETA);

  // Run flow
  if options.verbose {
    println!();
    println!("--- Run MCMF ---");
  }
  let graph = builder.build(true, options.verbose);
  let result = graph.mcmf();

  if options.verbose {
    println!();
    println!("--- Result ---");
    println!("Flow = {}, Cost = {}", result.0, result.1.abs());
    println!();
  }

  let sum_func1 = sum_func1 as f64 / (1.0 + (-ALPHA + BETA).exp());
  let score = result.1 / sum_func1;
  println!("{:.2}", score.abs());
}
