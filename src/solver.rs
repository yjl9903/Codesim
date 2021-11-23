use super::flow::*;
use std::cmp::*;
use std::collections::BTreeMap;

type CodeType = BTreeMap<u64, Vec<u64>>;

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

  pub fn construct(&self, omega: f64, alpha: f64, beta: f64) -> Builder {
    let size = 2 + self.code1.len() + self.code2.len();
    let source = self.code1.len() + self.code2.len();
    let sink = 1 + self.code1.len() + self.code2.len();
    let mut builder = Builder::new(size, source, sink);

    for (i, (func, body)) in self.code1.iter().enumerate() {
      let label = format!("1:{:#11x}", func);
      if self.verbose {
        println!("Label {:?}: {}", &label, i);
      }
      builder.set_label(i, label);
      builder.add_edge(source, i, body.len() as CapType, 0 as CostType);
    }
    for (i, (func, body)) in self.code2.iter().enumerate() {
      let label = format!("2:{:#11x}", func);
      let node = i + self.code1.len();
      if self.verbose {
        println!("Label {:?}: {}", &label, node);
      }
      builder.set_label(node, label);
      builder.add_edge(node, sink, body.len() as CapType, 0 as CostType);
    }

    for (i, f1) in self.code1.iter().enumerate() {
      for (j, f2) in self.code2.iter().enumerate() {
        let sim = similarity(omega, f1.1, f2.1);
        let sim_rev = similarity(omega, f1.1, f2.1);

        if self.verbose {
          println!("similarity(1:{:#11x}, 2:{:#11x}) = {}", f1.0, f2.0, sim);
          println!("similarity(2:{:#11x}, 1:{:#11x}) = {}", f2.0, f1.0, sim_rev);
        }

        let cost = 1.0
          / (1.0
            + (-alpha * (max(sim, sim_rev) as CostType / min(f1.1.len(), f2.1.len()) as CostType)
              + beta)
              .exp());

        if self.verbose {
          println!("Edge 1:{:#11x} -> 2:{:#11x} with cap = {}, cost = {}", f1.0, f2.0, sim, cost);
        }

        builder.add_edge(i, j + self.code1.len(), sim, cost);
      }
    }

    builder
  }
}

fn similarity(omega: f64, f1: &Vec<u64>, f2: &Vec<u64>) -> i64 {
  let omega = (omega * f1.len() as f64).ceil() as usize;
  let loop_end = if f2.len() > omega {
    f2.len() - omega
  } else {
    1
  };
  let mut ans = 0 as i64;
  for i in 0..loop_end {
    let cs = lcs(f1, f2, i, min(i + omega, f2.len()));
    ans = max(ans, cs as i64);
  }
  ans
}

fn lcs(f1: &Vec<u64>, f2: &Vec<u64>, start: usize, end: usize) -> usize {
  let mut g = vec![vec![0; end - start + 1]; f1.len() + 1];
  for i in 0..f1.len() {
    for j in start..end {
      g[i + 1][j + 1 - start] = max(g[i + 1][j - start], g[i][j - start + 1]);
      if f1[i] == f2[j] {
        g[i + 1][j + 1 - start] = max(g[i + 1][j + 1 - start], g[i][j - start] + 1);
      } else {
        g[i + 1][j + 1 - start] = max(g[i + 1][j + 1 - start], g[i][j - start]);
      }
    }
  }
  g[f1.len()][end - start]
}
