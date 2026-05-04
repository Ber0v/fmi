allPaths :: IntTree -> [[Int]]
allPaths Empty = []
allPaths (Node x Empty Empty) = [[x]]
allPaths (Node x left right) = map (x:) (allPaths left) ++ map (x:) (allPaths right)