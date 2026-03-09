merge :: (Ord a) => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x : xs) (y : ys)
  | x <= y = x : merge xs (y : ys)
  | otherwise = y : merge (x : xs) ys

main :: IO ()
main = do
  print (merge [1, 4, 5] [2, 3, 6, 7])
  print (merge [] [1, 2])