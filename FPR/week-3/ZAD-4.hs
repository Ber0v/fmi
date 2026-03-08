myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs


main :: IO()
main = do
    print(myLength [1, 2, 3, 4])
    print(myLength [])