isSorted :: (Ord a) => [a] -> Bool
isSorted [] = False
isSorted (x : xs)
  | null xs = True
  | x <= head xs = isSorted xs
  | otherwise = False

main :: IO ()
main = do
  print (isSorted [1, 2, 3, 5])
  print (isSorted [1, 5, 3])