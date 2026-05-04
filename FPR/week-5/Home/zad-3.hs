takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' f (x : xs)
  | f x = x : takeWhile' f xs
  | otherwise = []

dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' _ [] = []
dropWhile' f (x : xs)
  | f x = dropWhile' f xs
  | otherwise = x : xs

main :: IO ()
main = do
  print (takeWhile' (< 5) [1, 3, 5, 2, 4])
  print (dropWhile' (< 5) [1, 3, 5, 2, 4])