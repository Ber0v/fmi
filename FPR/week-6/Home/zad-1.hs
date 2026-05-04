primes :: Int -> [Int]
primes n = filter (\n -> n > 1 && null [d | d <- [2 .. n - 1], n `mod` d == 0]) [1 .. n]

main :: IO ()
main = do
  print (primes 30)