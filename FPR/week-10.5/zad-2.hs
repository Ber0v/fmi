eval :: Environment -> Expression -> Int
eval env (Const n) = n
eval env (Var name) =
  case lookup name env of
    Just v -> v
    Nothing -> error("Error")
eval env (Add e1 e2) = eval env e1 + eval env e2
eval env (Sub e1 e2) = eval env e1 - eval env e2
eval env (Mul e1 e2) = eval env e1 * eval env e2