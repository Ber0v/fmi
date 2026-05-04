f1 :: [Int] -> Int
f1 = length . filter even 

f2 :: [Int] -> Int
f2 = sum . map (*2)

f3 :: [Int] -> [Int]
f3 = reverse . map (+1)

main :: IO ()
main = do
    print (f1 [1, 2, 3, 4, 5])
    print (f2 [1, 2, 3, 4, 5])
    print (f3 [1, 2, 3, 4, 5])