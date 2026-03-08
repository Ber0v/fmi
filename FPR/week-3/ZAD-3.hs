isPrime :: Int -> Bool
isPrime n
    | n <= 1 = False
    | otherwise = checkDivisor 2
    where
        checkDivisor d
            | d * d > n = True
            | mod n d == 0 = False
            | otherwise = checkDivisor (d + 1)

main :: IO()
main = do
    print(isPrime 7)
    print(isPrime 10)