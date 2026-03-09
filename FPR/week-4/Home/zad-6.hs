isInfixOf' :: (Eq a) => [a] -> [a] -> Bool
isInfixOf' [] _ = False
isInfixOf' _ [] = False
isInfixOf' (x : xs) (y : ys)
  | x == y = True
  | otherwise = isInfixOf' xs ys

main :: IO ()
main = do
  print (isInfixOf' [1, 2] [1, 2, 3])
  print (isInfixOf' [1, 2] [3, 4, 5])