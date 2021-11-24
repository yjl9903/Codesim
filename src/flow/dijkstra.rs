use super::*;

#[derive(Copy, Clone)]
struct State {
  cost: CostType,
  node: usize,
}

pub const EPS: CostType = 1e-2;

impl Ord for State {
  fn cmp(&self, other: &Self) -> std::cmp::Ordering {
    if self.eq(other) {
      std::cmp::Ordering::Equal
    } else if (self.cost - other.cost).abs() <= EPS {
      self.node.cmp(&other.node)
    } else if self.cost < other.cost {
      std::cmp::Ordering::Greater
    } else {
      std::cmp::Ordering::Less
    }
  }
}

impl PartialOrd for State {
  fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
    Some(self.cmp(other))
  }
}

impl Eq for State {}

impl PartialEq for State {
  fn eq(&self, other: &Self) -> bool {
    (self.cost - other.cost).abs() <= EPS && self.node == other.node
  }
}

impl Graph {
  pub fn dijkstra(&self, start: usize) -> (Vec<f64>, Vec<Option<usize>>) {
    let mut vis = vec![false; self.n + 1];
    let mut dis = vec![COSTMAX; self.n + 1];
    let mut pre: Vec<Option<usize>> = vec![None; self.n + 1];

    dis[start] = 0 as CostType;
    let mut heap = BinaryHeap::new();
    heap.push(State {
      cost: dis[start],
      node: start,
    });

    while let Some(State { cost: d, node: u }) = heap.pop() {
      if vis[u] {
        continue;
      }
      vis[u] = true;
      if u == self.n {
        for to in 0..self.n {
          let cost = -self.phi[to];
          if dis[to] > d + cost + EPS {
            dis[to] = d + cost;
            heap.push(State {
              cost: dis[to],
              node: to,
            });
          }
        }
      } else {
        for e in self.succ_of(u) {
          let to = e.to;
          let cost = self.reduced_cost(&e);
          if e.cap != 0 && dis[to] > d + cost + EPS {
            dis[to] = d + cost;
            pre[to] = Some(e.id);
            heap.push(State {
              cost: dis[to],
              node: to,
            });
          }
        }
      }
    }

    (dis, pre)
  }

  fn succ_of(&self, u: usize) -> Vec<Edge> {
    self.succ[u]
      .iter()
      .map(|id| self.edges[*id].clone())
      .collect()
  }
}
