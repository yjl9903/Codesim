use std::collections::HashMap;

pub type CapType = i64;

pub type CostType = f64;

pub struct Graph {
  n: usize,
  source: usize,
  sink: usize,
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

  pub fn build(&self) -> Graph {
    Graph {
      n: self.n,
      source: self.source,
      sink: self.sink,
    }
  }
}

impl Graph {
  pub fn mcmf(&self) -> (CapType, CostType) {
    Default::default()
  }
}
