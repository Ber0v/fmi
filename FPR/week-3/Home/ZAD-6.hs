sumDivisors :: Int -> Int -> Int
sumDivisors n d
    | d >= n = 0
    | mod n d == 0 = d + sumDivisors n (d + 1)
    | otherwise = sumDivisors n (d + 1)

isPerfect :: Int -> Bool
isPerfect n = n == sumDivisors n 1

main :: IO ()
main = do
    print (isPerfect 6)
    print (isPerfect 28)
    print (isPerfect 12)