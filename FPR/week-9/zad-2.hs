safeMax :: Ord a => [a] -> Maybe a
safeMax [] = Nothing
safeMax (x:xs) = Just (foldl max x xs)

safeMin :: Ord a => [a] -> Maybe a
safeMin [] = Nothing
safeMin (x:xs) = Just (foldl min x xs)

main :: IO ()
main = do
    print (safeMax [3, 1, 4, 1, 5])
    print (safeMax ([] :: [Int]))
    print (safeMin [3, 1, 4, 1, 5])
