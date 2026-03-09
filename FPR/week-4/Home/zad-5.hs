removeDuplicates :: (Eq a) => [a] -> [a]
removeDuplicates [] = []
removeDuplicates (x : xs)
  | elem x xs = removeDuplicates xs
  | otherwise = x : removeDuplicates xs

main :: IO ()
main = do
  print (removeDuplicates [1, 1, 2, 2, 2, 3, 1, 1])
  print (removeDuplicates "aaabbcca")