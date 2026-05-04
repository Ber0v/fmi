quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort [y| y <- xs, y < x] ++ [x] ++ quickSort [y| y <- xs, y >= x]

main :: IO ()
main = do
    print (quickSort [5, 2, 8, 1, 4, 7, 3])