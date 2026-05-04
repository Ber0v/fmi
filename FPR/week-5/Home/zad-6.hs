any' :: (a -> Bool) -> [a] -> Bool
any' f [] = False
any' f (x : xs)
  | f x = True
  | otherwise = any' f xs

all' :: (a -> Bool) -> [a] -> Bool
all' f [] = True
all' f (x : xs)
  | f x = all' f xs
  | otherwise = False

main :: IO ()
main = do
  print (any' even [1, 3, 5, 4])
  print (all' even [2, 4, 6])