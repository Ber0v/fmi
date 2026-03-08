toBinary :: Int -> [Int]
toBinary x 
        |x <= 0 = []
        |mod x 2 == 0 = 0 : toBinary(div x 2)
        |otherwise = 1 : toBinary(div x 2)

main :: IO()
main = do
    print (toBinary 13)
    print(toBinary 0)