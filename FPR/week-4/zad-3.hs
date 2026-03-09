myConcat :: [[a]] -> [a]
myConcat [] = []
myConcat (x : xs) = x ++ myConcat xs

main :: IO ()
main = do
  print (myConcat [[1, 2], [3, 4], [5, 6]])