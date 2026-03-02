isValidDate :: Int -> Int -> Int -> Bool
isValidDate d m y
    | y <= 0 = False
    | m < 1 || m > 12 = False
    | d < 1 = False
    | m == 2 = d <= febDays
    | elem m [4,6,9,11] = d <= 30
    | otherwise = d <= 31
    where
        febDays
            | isLeap y = 29
            | otherwise = 28

        isLeap year =
            mod year 400 == 0 ||
            (mod year 4 == 0 && mod year 100 /= 0)

main :: IO ()
main = do
    print (isValidDate 29 2 2024)
    print (isValidDate 29 2 2023)
    print (isValidDate 31 4 2025)