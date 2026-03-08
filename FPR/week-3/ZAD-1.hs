sumFirst :: Int -> Int
sumFirst x
    | x == 0 = 0
    | otherwise = x + sumFirst (x - 1)

main :: IO ()
main = do
    print (sumFirst 5)