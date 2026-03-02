isTriangle :: Double -> Double -> Double -> Bool
isTriangle a b c
    | a + b > c && b + c > a && c + a > b = True
    | otherwise = False

main :: IO()
main = do
    print(isTriangle 3 4 5)
    print(isTriangle 1 2 10)
