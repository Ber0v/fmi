compress :: (Eq a) => [a] -> [a]
compress [] = []
compress [x] = [x]
compress (x : y : xs)
  | x == y = compress (y : xs)
  | otherwise = x : compress (y : xs)

main :: IO ()
main = do
  print (compress [1, 1, 2, 2, 2, 3, 1, 1])
  print (compress "aaabbcca")