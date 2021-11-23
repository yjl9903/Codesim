use std::collections::HashMap;

type CodeType = HashMap<u64, Vec<u64>>;

pub struct Solver {
  code1: CodeType,
  code2: CodeType,
  verbose: bool,
}

impl Solver {
  pub fn new(code1: CodeType, code2: CodeType, verbose: bool) -> Self {
    Self {
      code1,
      code2,
      verbose,
    }
  }

  pub fn construct(&self, omega: f64, _alpha: f64, _beta: f64) {
    for f1 in self.code1.iter() {
      for f2 in self.code2.iter() {
        let value = similarity(omega, f1.1, f2.1);

        if self.verbose {
          println!("similarity(1:{:#11x}, 2:{:#11x}) = {}", f1.0, f2.0, value);
        }
      }
    }
  }
}

fn similarity(omega: f64, f1: &Vec<u64>, f2: &Vec<u64>) -> i64 {
  f1.len() as i64
}
