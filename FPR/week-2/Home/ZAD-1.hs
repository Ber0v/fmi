typeOfTriangle :: Double -> Double -> Double -> String
typeOfTriangle a b c
    | not valid = "Невалиден"
    | a == b && b == c = "Равностранен"
    | a == b || a == c || b == c = "Равнобедрен"
    | otherwise = "Разностранен"
    where
        valid = a + b > c && a + c > b && b + c > a

main :: IO ()
main = do
    putStrLn (typeOfTriangle 3 3 3)
    putStrLn (typeOfTriangle 3 3 5)
    putStrLn (typeOfTriangle 3 4 5)
    putStrLn (typeOfTriangle 1 2 10)