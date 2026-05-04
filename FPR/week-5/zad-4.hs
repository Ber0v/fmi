sumFoldr :: (Num a) => [a] -> a
sumFoldr [] = 0
sumFoldr (x : xs) = x + sumFoldr xs

lengthFoldr :: [a] -> Int
lengthFoldr [] = 0
lengthFoldr (x : xs) = 1 + lengthFoldr xs

reverseFoldl :: [a] -> [a]
reverseFoldl [] = []
reverseFoldl (x : xs) = reverseFoldl xs ++ [x]

main :: IO ()
main = do
  print (sumFoldr [1, 2, 3, 4])
  print (lengthFoldr [1, 2, 3, 4])
  print (reverseFoldl [1, 2, 3, 4])