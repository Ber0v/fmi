myElem :: Eq a => a -> [a] -> Bool
myElem n [] = False
myElem n (x:xs) 
                |n == x = True
                |otherwise = myElem n xs

main :: IO()
main = do
    print(myElem 3 [1, 2, 3, 4])
    print(myElem 5 [1, 2, 3, 4])