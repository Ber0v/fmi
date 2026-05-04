countBy :: (a -> Bool) -> [a] -> Int
countBy f [] = 0
countBy f (x : xs)
  | f x = 1 + countBy f xs
  | otherwise = countBy f xs

main :: IO ()
main = do
  print (countBy even [1 .. 10])
  print (countBy (> 3) [1, 5, 2, 8, 3])