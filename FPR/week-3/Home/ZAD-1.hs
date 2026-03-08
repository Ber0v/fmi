digitSum :: Int -> Int
digitSum x
        |x == 0 = 0
        |otherwise = mod x 10 + digitSum(div x 10)

main :: IO ()
main = do
    print (digitSum 123)
    print (digitSum 9999)