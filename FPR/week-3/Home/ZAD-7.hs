horner :: [Double] -> Double -> Double
horner [] _ = 0
horner (a:as) x = a + x * horner as x

main :: IO ()
main = do
    print (horner [1,2,3] 2)