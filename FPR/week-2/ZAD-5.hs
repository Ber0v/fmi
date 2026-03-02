signum' :: Int -> Int
signum' x
  | x > 0 = 1
  | x == 0 = 0
  | x < 0 = -1

main :: IO()
main = do
    print(signum' 5)
    print(signum' 0)
    print(signum' (-3))