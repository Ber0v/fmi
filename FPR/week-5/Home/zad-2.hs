zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x : xs) (y : ys) = f x y : zipWith' f xs ys

main :: IO ()
main = do
  print (zipWith' (+) [1, 2, 3] [10, 20, 30])
  print (zipWith' max [1, 5, 3] [4, 2, 6])