safeIndex :: [a] -> Int -> Maybe a
safeIndex [] _ = Nothing
safeIndex (x:_) 0 = Just x
safeIndex (_:xs) n = safeIndex xs (n - 1)

main :: IO ()
main = do
    print (safeIndex [10, 20, 30] 1)
    print (safeIndex [10, 20, 30] 5)