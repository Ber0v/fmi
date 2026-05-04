inorder :: IntTree -> [Int]
inorder Empty = []
inorder (Node x left right) =
  inorder left ++ [x] ++ inorder right

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x:y:xs) =
  x < y && isSorted (y:xs)

isBST :: IntTree -> Bool
isBST tree = isSorted (inorder tree)