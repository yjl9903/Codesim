mod flow;
mod loader;
mod solver;

#[macro_use]
extern crate lazy_static;

use loader::{DumpResult, Loader};
use solver::Solver;
use std::path::PathBuf;
use structopt::StructOpt;

const OMEGA: f64 = 1.5;
const ALPHA: f64 = 2.0;
const BETA: f64 = 0.5;

#[derive(StructOpt)]
#[structopt(name = "codesim", about = "Diff two single C++ code file")]
struct CliOption {
  #[structopt(short = "-v", long = "--verbose", help = "Verbose log")]
  verbose: bool,

  #[structopt(long = "--skip-compile", help = "Skip compile")]
  skip_comiple: bool,

  #[structopt(parse(from_os_str), help = "source code", required_if("files", ""))]
  code1: Option<PathBuf>,

  #[structopt(parse(from_os_str), help = "target code", required_if("files", ""))]
  code2: Option<PathBuf>,

  #[structopt(long = "--files", help = "extra files")]
  files: Vec<PathBuf>,
}

fn main() {
  let options = CliOption::from_args();

  let is_empty = options.files.is_empty();
  if is_empty {
    // Two file
    let code1 = options.code1.clone();
    let code1 = code1.unwrap();
    let code2 = options.code2.clone();
    let code2 = code2.unwrap();
    if options.verbose {
      println!("Diff: {:?} v.s. {:?}", code1, code2);
    }
    let (func1, func2) = compile_two_file(&code1, &code2, &options);
    println!("{:.2}", diff_two_file(func1, func2, &options));
  } else {
    // multi files
    if options.verbose {
      println!("Diff {} files", options.files.len());
      for (i, path) in options.files.iter().enumerate() {
        println!("{:?}. {:?}", i + 1, path);
      }
    }

    let lds: Vec<_> = options
      .files
      .iter()
      .map(|path| Loader::new(path, options.skip_comiple, options.verbose))
      .map(|ld| {
        ld.compile();
        let sym = ld.symbol_table();
        ld.dump(sym)
      })
      .collect();

    let mut rows = Vec::new();
    for i in 0..lds.len() {
      for j in 0..lds.len() {
        if i == j {
          continue;
        }
        let path1 = &options.files[i];
        let func1 = &lds[i];
        let path2 = &options.files[j];
        let func2 = &lds[j];
        let result = diff_two_file(func1.clone(), func2.clone(), &options);
        rows.push((result, path1.clone(), path2.clone()));
      }
    }
    rows.sort_by(|a, b| b.0.partial_cmp(&a.0).unwrap());
    println!("id,code1,code2,similarity");
    for (id, (score, p1, p2)) in rows.into_iter().enumerate() {
      println!("{},{:?},{:?},{:.2}", id + 1, p1, p2, score);
    }
  }
}

fn compile_two_file(
  code1: &PathBuf,
  code2: &PathBuf,
  options: &CliOption,
) -> (DumpResult, DumpResult) {
  if options.verbose {
    println!();
    println!("--- Load code1: {:?} ---", code1);
  }
  let ld1 = Loader::new(code1, options.skip_comiple, options.verbose);
  ld1.compile();
  let sym1 = ld1.symbol_table();
  let func1 = ld1.dump(sym1);

  if options.verbose {
    println!();
    println!("--- Load code2: {:?} ---", code2);
  }
  let ld2 = Loader::new(code2, options.skip_comiple, options.verbose);
  ld2.compile();
  let sym2 = ld2.symbol_table();
  let func2 = ld2.dump(sym2);

  (func1, func2)
}

fn diff_two_file(func1: DumpResult, func2: DumpResult, options: &CliOption) -> f64 {
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

  score.abs()
}
