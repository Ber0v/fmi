concatMap' :: (a -> [b]) -> [a] -> [b]
concatMap' f [] = []
concatMap' f (x : xs) = f x ++ concatMap' f xs

main :: IO ()
main = do
  print (concatMap' (\x -> [x, x * 10]) [1, 2, 3])