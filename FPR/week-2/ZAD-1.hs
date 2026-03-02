max3 :: Int -> Int -> Int -> Int
max3 x y z
    | x > y && x > z = x
    | y > x && y > z = y
    | otherwise = z

main :: IO()
main = do
  print (max3 3 7 2)