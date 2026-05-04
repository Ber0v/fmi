data Tree a = Empty | Node (Tree a) a (Tree a)

bstInsert :: (Ord a) => a -> Tree a -> Tree a
bstInsert x Empty = Node Empty x Empty
bstInsert x (Node l y r)
  | x < y = Node (bstInsert y l) y r
  | x > y = Node l y (bstInsert x r)
  | otherwise = bstInsert x r

bstSearch :: (Ord a) => a -> Tree a -> Bool
bstSearch _ Empty = False
bstSearch x (Node l y r)
  | x < y = bstSearch x l
  | x > y = bstSearch x r
  | otherwise = True

fromList :: (Ord a) => [a] -> Tree a
fromList = foldr bstInsert Empty