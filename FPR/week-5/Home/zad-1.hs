mapFoldr :: (a -> b) -> [a] -> [b]
mapFoldr f [] = []
mapFoldr f (x : xs) = f x : mapFoldr f xs

filterFoldr :: (a -> Bool) -> [a] -> [a]
filterFoldr f [] = []
filterFoldr f (x : xs)
  | f x = x : filterFoldr f xs
  | otherwise = filterFoldr f xs

main :: IO ()
main = do
  print (mapFoldr (* 2) [1, 2, 3, 4])
  print (filterFoldr even [1, 2, 3, 4])