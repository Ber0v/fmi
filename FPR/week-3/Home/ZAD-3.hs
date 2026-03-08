fibonacci :: Int -> Int
fibonacci n = helper n 0 1

helper :: Int -> Int -> Int -> Int
helper 0 a b = a
helper n a b = helper (n - 1) b (a + b)

main :: IO()
main = do
    print(fibonacci 10)
    print(fibonacci 30)