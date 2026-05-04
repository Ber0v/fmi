prune :: Int -> IntTree -> IntTree
prune _ Empty = Empty
prune 0 (Node v _ _) = Node v Empty Empty
prune k (Node x left right) = Node x (prune (k-1) left) (prune (k-1) right