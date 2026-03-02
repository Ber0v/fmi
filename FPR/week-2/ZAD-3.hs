swap :: (a, b) -> (b, a)
swap (a,b) = (b,a)

main :: IO()
main = do
    print(swap (1, 2))