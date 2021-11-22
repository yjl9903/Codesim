use clang::*;

pub fn get_func_decl<'a>(tu: &'a TranslationUnit) -> Vec<Entity<'a>> {
  let mut funcs: Vec<Entity> = Vec::new();
  tu.get_entity().visit_children(|cur, _| {
    let kind = cur.get_kind();
    if kind == EntityKind::FunctionDecl
      || kind == EntityKind::FunctionTemplate
      || kind == EntityKind::Method
      || kind == EntityKind::Constructor
      || kind == EntityKind::Destructor
      || kind == EntityKind::LambdaExpr
    {
      funcs.push(cur);
      EntityVisitResult::Continue
    } else {
      EntityVisitResult::Recurse
    }
  });
  funcs
}
