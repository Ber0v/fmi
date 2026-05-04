groupBy' :: (a -> a -> Bool) -> [a] -> [[a]]
groupBy' _ [] = []
groupBy' f (x : xs)
  | null xs = [[x]]
  | f x (head xs) = (x : head (groupBy' f xs)) : tail (groupBy' f xs)
  | otherwise = [x] : groupBy' f xs

main :: IO ()
main = do
  print (groupBy' (==) [1, 1, 2, 2, 2, 3, 3, 1])
  print (groupBy' (<) [1, 3, 5, 2, 4, 6])
