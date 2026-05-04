getLevel :: Int -> IntTree -> [Int]
getLevel _ Empty = []
getLevel 0 (Node x _ _) = [x]
getLevel x (Node _ left right) = getLevel (x-1) left ++ getLevel (x-1) right