median3 :: (Int, Int, Int) -> Int
median3 (a, b, c) = a + b + c - minimum [a, b, c] - maximum [a, b, c]

main :: IO ()
main = do
    print (median3 (3, 1, 2))
    print (median3 (5, 5, 3))