partition' :: (a -> Bool) -> [a] -> ([a], [a])
partition' _ [] = ([], [])
partition' f (x : xs)
  | f x = (x : ys, zs)
  | otherwise = (ys, x : zs)
  where
    (ys, zs) = partition' f xs

main :: IO ()
main = do
  print (partition' even [1 .. 10])