insert :: Int -> IntTree -> IntTree
insert x Empty = Node x Empty Empty
insert x (Node v left right)
    |x == v = Node v left right
    |x < v = Node v (insert x left) right
    |otherwise = Node v left (insert x right)