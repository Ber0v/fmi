delete :: Int -> IntTree -> IntTree
delete _ Empty = Empty
delete x (Node v left right)
  | x < v = Node v (delete x left) right
  | x > v = Node v left (delete x right)
  | otherwise = deleteRoot (Node v left right)

deleteRoot :: IntTree -> IntTree
deleteRoot (Node _ Empty Empty) = Empty
deleteRoot (Node _ left Empty) = left
deleteRoot (Node _ Empty right) = right
deleteRoot (Node _ left right) =
  Node smallest left (delete smallest right)
  where
    smallest = treeMin right

treeMin :: IntTree -> Int
treeMin (Node v Empty _) = v
treeMin (Node _ left _) = treeMin left