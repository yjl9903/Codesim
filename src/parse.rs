use std::path::PathBuf;

use clang::*;

lazy_static! {
  static ref CLANG: Clang = Clang::new().unwrap();
}

pub struct Parser<'a> {
  index: Index<'a>,
}

impl Parser<'_> {
  pub fn new() -> Parser<'static> {
    let index = Index::new(&CLANG, false, false);
    Parser { index }
  }

  pub fn parse(&self, file: PathBuf) -> TranslationUnit {
    let mut parser = self.index.parser(file);
    parser.arguments(&["--std=c++17", "-pedantic"]);
    parser.parse().unwrap()
  }
}
