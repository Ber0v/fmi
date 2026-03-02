dotProduct :: (Double, Double) -> (Double, Double) -> Double
dotProduct (x1, y1) (x2, y2) =
    x1 * x2 + y1 * y2

main :: IO ()
main = do
    print (dotProduct (1, 2) (3, 4))