mod flow;
mod loader;
mod solver;

#[macro_use]
extern crate lazy_static;

use loader::{DumpResult, Loader};
use solver::Solver;
use std::{fs::File, io::prelude::*, path::PathBuf};
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

  #[structopt(long = "--norm", help = "Normalize final score")]
  is_norm: bool,

  #[structopt(long = "--csv", help = "Output CSV")]
  csv: Option<PathBuf>,

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
      println!();
    }
    let (func1, func2) = compile_two_file(&code1, &code2, &options);
    println!("{}", diff_two_file(func1, func2, options.verbose).to_string(options.is_norm));
  } else {
    // multi files
    if options.verbose {
      println!("Diff {} files", options.files.len());
      for (i, path) in options.files.iter().enumerate() {
        println!("{:?}. {:?}", i + 1, path);
      }
    }

    let verbose = options.verbose;

    let lds: Vec<_> = options
      .files
      .iter()
      .map(|path| Loader::new(path, options.skip_comiple, options.verbose))
      .map(|ld| {
        if verbose {
          println!("");
        }

        ld.compile().map_or_else(
          |msg| {
            eprintln!("Fail to compile {:?}", ld.source);
            if options.verbose {
              eprintln!("{}", msg);
            }
            None
          },
          |_| {
            let sym = ld.symbol_table();
            Some(ld.dump(sym))
          },
        )
      })
      .collect();

    if options.verbose {
      println!();
      println!("--- Pairwise Diff ---");
    }
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

        if func1.is_none() || func2.is_none() {
          continue;
        }

        let result = diff_two_file(func1.clone().unwrap(), func2.clone().unwrap(), false);
        rows.push((result.eval(options.is_norm), path1.clone(), path2.clone()));

        if options.verbose {
          println!("{:?} v.s. {:?} : {}", path1, path2, result.to_string(options.is_norm));
        }
      }
    }
    if options.verbose {
      println!();
    }

    rows.sort_by(|a, b| b.0.partial_cmp(&a.0).unwrap());
    let csv_file = options.csv.map(|f| File::create(f).unwrap());
    if let Some(mut file) = csv_file {
      write!(file, "id,code1,code2,similarity\n").unwrap();
      for (id, (score, p1, p2)) in rows.into_iter().enumerate() {
        write!(file, "{},{:?},{:?},{:.2}\n", id + 1, p1, p2, score).unwrap();
      }
    } else {
      println!("id,code1,code2,similarity");
      for (id, (score, p1, p2)) in rows.into_iter().enumerate() {
        println!("{},{:?},{:?},{:.2}", id + 1, p1, p2, score);
      }
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
  if let Err(msg) = ld1.compile() {
    eprintln!("{}", msg);
  }
  let sym1 = ld1.symbol_table();
  let func1 = ld1.dump(sym1);

  if options.verbose {
    println!();
    println!("--- Load code2: {:?} ---", code2);
  }
  let ld2 = Loader::new(code2, options.skip_comiple, options.verbose);
  if let Err(msg) = ld2.compile() {
    eprintln!("{}", msg);
  }
  let sym2 = ld2.symbol_table();
  let func2 = ld2.dump(sym2);

  (func1, func2)
}

fn diff_two_file(func1: DumpResult, func2: DumpResult, verbose: bool) -> Score {
  let sum_func1 = func1.iter().map(|(_, body)| body.len()).sum::<usize>();

  // Run diff
  let solver = Solver::new(func1, func2, verbose);
  if verbose {
    println!();
    println!("--- Calc function similarity ---");
  }
  let builder = solver.construct(OMEGA, ALPHA, BETA);

  // Run flow
  if verbose {
    println!();
    println!("--- Run MCMF ---");
  }
  let graph = builder.build(true, verbose);
  let result = graph.mcmf();

  if verbose {
    println!();
    println!("--- Result ---");
    println!("Flow = {}, Cost = {}", result.0, result.1.abs());
    println!();
  }

  Score::new(result.1, sum_func1)
}

struct Score(f64, usize);

impl Score {
  fn new(score: f64, sum: usize) -> Score {
    Score(score, sum)
  }

  fn to_string(&self, is_norm: bool) -> String {
    format!("{:.2}", self.eval(is_norm))
  }

  fn eval(&self, is_norm: bool) -> f64 {
    let score = if is_norm {
      let sum_func = self.1 as f64 / (1.0 + (-ALPHA + BETA).exp());
      self.0 / sum_func
    } else {
      self.0 / self.1 as f64
    };
    if score < flow::EPS {
      0.0
    } else {
      score
    }
  }
}
