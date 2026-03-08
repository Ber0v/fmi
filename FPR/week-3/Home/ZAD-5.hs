sumDivisors :: Int -> Int
sumDivisors n = helper n 1

helper :: Int -> Int -> Int
helper n d
    | d > n = 0
    | mod n d == 0 = d + helper n (d + 1)
    | otherwise = helper n (d + 1)

main :: IO ()
main = do
    print (sumDivisors 12)
    print (sumDivisors 7)