intersect' :: (Eq a) => [a] -> [a] -> [a]
intersect' [] _ = []
intersect' _ [] = []
intersect' (x : xs) (y : ys) = if x == y then x : intersect' xs ys else intersect' xs (y : ys)

main :: IO ()
main = do
  print (intersect' [1, 2, 3, 4] [3, 4, 5, 6])