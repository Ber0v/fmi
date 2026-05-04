squaresDiv3 :: Int -> [Int]
squaresDiv3 n = filter (\x -> mod x 3 == 0) (map (^ 2) [1 .. n])

sumPairs :: Int -> [(Int, Int)]
sumPairs n = filter (\(x, y) -> x + y == n) [(x, y) | x <- [1 .. n], y <- [1 .. n]]

main :: IO ()
main = do
  print (squaresDiv3 15)
  print (sumPairs 5)