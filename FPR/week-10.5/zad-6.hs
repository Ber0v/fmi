getLeaves :: IntTree -> [Int]
getLeaves Empty = []
getLeaves (Node x Empty Empty) = [x]
getLeaves (Node _ left right)  = getLeaves left ++ getLeaves right