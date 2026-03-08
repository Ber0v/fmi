isBalanced :: String -> Bool
isBalanced s = helper s 0

helper :: String -> Int -> Bool
helper [] counter = counter == 0
helper (x:xs) counter
    | x == '(' = helper xs (counter + 1)
    | x == ')' =
        if counter == 0
        then False
        else helper xs (counter - 1)
    | otherwise = helper xs counter

main :: IO ()
main = do
    print (isBalanced "()()")
    print (isBalanced ")(")
    print (isBalanced "(()")