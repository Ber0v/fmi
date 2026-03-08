countDigits :: Int -> Int
countDigits x
            |x < 10 = 1
            |otherwise = 1 + countDigits(div x 10)

main :: IO()
main = do
    print(countDigits 123)
    print(countDigits 0)