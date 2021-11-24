mod dijkstra;

use std::collections::{BinaryHeap, HashMap, HashSet};

pub use dijkstra::EPS;

pub type CapType = i64;

pub type CostType = f64;

pub const COSTARG: CostType = 100.0;

pub const COSTMAX: CostType = 100000.0 * COSTARG;

pub struct Graph {
  n: usize,
  phi: Vec<CostType>,
  edges: Vec<Edge>,
  succ: Vec<Vec<usize>>,
  max_cost: bool,
  verbose: bool,
}

pub struct Builder {
  n: usize,
  source: usize,
  sink: usize,
  labels: HashMap<usize, String>,
  edges: Vec<(usize, usize, CapType, CostType)>,
}

impl Builder {
  pub fn new(n: usize, source: usize, sink: usize) -> Self {
    let mut builder = Self {
      n,
      source,
      sink,
      labels: HashMap::new(),
      edges: Vec::new(),
    };

    builder.set_label(source, "source".to_string());
    builder.set_label(sink, "sink".to_string());

    builder
  }

  pub fn set_label(&mut self, node: usize, label: String) {
    if let Some(_) = self.labels.get(&node) {
      panic!("Can not re-label");
    }
    self.labels.insert(node, label);
  }

  pub fn add_edge(&mut self, from: usize, to: usize, cap: CapType, cost: CostType) {
    self.edges.push((from, to, cap, cost));
  }

  pub fn build(&self, max_cost: bool, verbose: bool) -> Graph {
    let mut edges = vec![];
    let mut succ = vec![vec![]; self.n];

    let mul_cost = if max_cost {
      -1 as CostType
    } else {
      1 as CostType
    };

    let mut add = |from: usize, to: usize, cap: CapType, cost: CostType| {
      let normal_id = edges.len();
      let normal = Edge {
        id: normal_id,
        from,
        to,
        cap: 0 as CapType,
        raw_cap: cap,
        cost: mul_cost * cost, // Maxmimum cost
        kind: EdgeKind::Normal(normal_id + 1),
      };
      edges.push(normal);

      let rev_id = edges.len();
      let rev = Edge {
        id: rev_id,
        from: to,
        to: from,
        cap: 0 as CapType,
        raw_cap: 0 as CapType,
        cost: -mul_cost * cost, // Maxmimum cost
        kind: EdgeKind::Rev(normal_id),
      };
      edges.push(rev);

      succ[from].push(normal_id);
      succ[to].push(rev_id);
    };

    for (from, to, cap, cost) in self.edges.iter() {
      add(*from, *to, *cap, *cost * COSTARG);
    }

    // Last edge for T -> S
    let sum_cap = self.edges.iter().map(|(_, _, cap, _)| cap).sum::<CapType>();
    add(self.sink, self.source, sum_cap + 5, -mul_cost * COSTMAX);

    Graph {
      n: self.n,
      phi: vec![0 as CostType; self.n],
      edges,
      succ,
      max_cost,
      verbose,
    }
  }
}

#[derive(Debug, Clone)]
enum EdgeKind {
  Normal(usize),
  Rev(usize),
}

#[derive(Debug, Clone)]
struct Edge {
  id: usize,
  from: usize,
  to: usize,
  cap: CapType,
  raw_cap: CapType,
  cost: CostType,
  kind: EdgeKind,
}

impl Edge {
  fn is_normal(&self) -> bool {
    if let EdgeKind::Normal(_) = self.kind {
      true
    } else {
      false
    }
  }

  fn rev(&self) -> usize {
    match self.kind {
      EdgeKind::Normal(r) => r,
      EdgeKind::Rev(r) => r,
    }
  }
}

impl Graph {
  pub fn mcmf(mut self) -> (CapType, CostType) {
    let max_cap = self.edges.iter().map(|e| e.raw_cap).max().unwrap();
    let hight_bit = CapType::BITS - max_cap.leading_zeros();

    let normal_edges = self
      .edges
      .iter()
      .filter(|e| e.is_normal())
      .map(|e| e.id)
      .collect::<Vec<usize>>();
    for bit in (0..hight_bit).rev() {
      if self.verbose {
        println!("Turn {}:", bit);
      }

      for e in self.edges.iter_mut() {
        e.cap *= 2;
      }
      for &eid in normal_edges.iter() {
        let raw_cap = self.edges[eid].raw_cap;
        if ((raw_cap >> bit) & 1) != 0 {
          self.add_one_cap(eid);
        }
      }
    }

    let mut cost = 0 as CostType;
    let edges_len = self.edges.len();
    for e in self.edges.iter().take(edges_len - 2) {
      if e.is_normal() {
        cost += e.cost * self.edges[e.rev()].cap as CostType;
      }
    }
    if self.max_cost {
      cost = -cost;
    }
    (self.edges[edges_len - 1].cap, cost)
  }

  fn add_one_cap(&mut self, eid: usize) {
    if self.edges[eid].cap != 0 {
      self.edges[eid].cap += 1;
      return;
    }

    let from = self.edges[eid].from;
    let to = self.edges[eid].to;

    if self.verbose {
      println!("Add: {} -> {}", from, to);
    }

    let (dis, pre) = self.dijkstra(to);

    if dis[from] < COSTMAX - EPS
      && dis[from] + self.reduced_cost(&self.edges[eid]) < 0 as CostType - EPS
    {
      let rev = self.edges[eid].rev();
      self.edges[rev].cap += 1;

      if self.verbose {
        print!("Flow 1: {}", self.edges[eid].to);
      }

      let mut u = from;
      let v = to;
      let mut set: HashSet<usize> = HashSet::new();
      while u != v {
        if set.contains(&u) {
          eprintln!("Error: Find negative loop");
          break;
        } else {
          set.insert(u);
        }
        if let Some(xid) = pre[u] {
          self.edges[xid].cap -= 1;
          let rev = self.edges[xid].rev();
          self.edges[rev].cap += 1;

          if self.verbose {
            print!(" -> {}", u);
          }

          u = self.edges[xid].from;
        } else {
          panic!("Path fail");
        }
      }

      if self.verbose {
        println!(" -> {}", self.edges[eid].to);
      }
    } else {
      if self.verbose {
        println!("Flow 2: {} -> {}", self.edges[eid].from, self.edges[eid].to);
      }

      self.edges[eid].cap += 1;
    }

    let mut max_dis = 0 as CostType;
    let cur_len = self.reduced_cost(&self.edges[eid]);
    for i in 0..self.n {
      if dis[i] < COSTMAX - EPS && dis[i] > max_dis + EPS {
        max_dis = dis[i];
      }
    }

    for i in 0..self.n {
      if dis[i] < COSTMAX - EPS {
        self.phi[i] += dis[i];
      } else {
        self.phi[i] += max_dis;
        if cur_len < 0 as CostType - EPS {
          self.phi[i] -= cur_len;
        }
      }
    }

    let (dis, _) = self.dijkstra(self.n);
    for i in 0..self.n {
      self.phi[i] += dis[i];
    }
  }

  fn reduced_cost(&self, e: &Edge) -> CostType {
    self.phi[e.from] + e.cost - self.phi[e.to]
  }
}

#[cfg(test)]
mod test_flow {
  use super::*;

  #[test]
  fn example() {
    let mut builder = Builder::new(5, 4, 3);
    builder.add_edge(4, 2, 30, 2.0);
    builder.add_edge(4, 3, 20, 3.0);
    builder.add_edge(2, 3, 20, 1.0);
    builder.add_edge(2, 1, 30, 9.0);
    builder.add_edge(1, 3, 40, 5.0);
    let graph = builder.build(false, true);
    let result = graph.mcmf();
    dbg!(result);
    assert_eq!(result.0, 50);
    assert!((result.1 - 280.0 * COSTARG).abs() < EPS);
  }
}
