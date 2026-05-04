evalSimple :: Expression -> Int
evalSimple (Const n) = n
evalSimple (Add e1 e2) = evalSimple e1 + evalSimple e2
evalSimple (Sub e1 e2) = evalSimple e1 - evalSimple e2
evalSimple (Mul e1 e2) = evalSimple e1 * evalSimple e2

