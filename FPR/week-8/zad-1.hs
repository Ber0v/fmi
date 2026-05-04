data Tree a = Empty | Node (Tree a) a (Tree a)

treeSize :: Tree a -> Int
treeSize Empty = 0
treeSize (Node l _ r) = 1 + treeSize l + treeSize r

treeHeight :: Tree a -> Int
treeHeight Empty = 0
treeHeight (Node l _ r) = 1 + max (treeHeight l) (treeHeight r)

treeSum :: (Num a) => Tree a -> a
treeSum Empty = 0
treeSum (Node l x r) = x + treeSum l + treeSum r

countLeaves :: Tree a -> Int
countLeaves Empty = 0
countLeaves (Node Empty _ Empty) = 1
countLeaves (Node l _ r) = countLeaves l + countLeaves r

main :: IO ()
main = do
  print (treeSize (Node (Node Empty 1 Empty) 2 (Node Empty 3 Empty)))
  print (treeHeight (Node (Node Empty 1 Empty) 2 (Node Empty 3 Empty)))
  print (treeSum (Node (Node Empty 1 Empty) 2 (Node Empty 3 Empty)))
  print (countLeaves (Node (Node Empty 1 Empty) 2 (Node Empty 3 Empty)))