infix 4 ~=

(~=) :: Double -> Double -> Bool
a ~= b = abs (a - b) <= 1e-9

main :: IO ()
main = do
    print (0.1 + 0.2 ~= 0.3)
    print (1.0 ~= 1.000000001)
    print (1.0 ~= 1.1)