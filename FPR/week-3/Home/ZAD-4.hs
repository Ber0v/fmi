reverseDigits :: Int -> Int -> Int
reverseDigits 0 acc = acc
reverseDigits n acc = reverseDigits (div n 10) (acc * 10 + mod n 10)

isPalindrome :: Int -> Bool
isPalindrome x = x == reverseDigits x 0

main :: IO ()
main = do
    print (isPalindrome 12321)
    print (isPalindrome 123)