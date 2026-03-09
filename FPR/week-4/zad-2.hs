myZip :: [a] -> [b] -> [(a, b)]
myZip [] _ = []
myZip _ [] = []
myZip (x : xs) (y : ys) = (x, y) : myZip xs ys

main :: IO ()
main = do
  print (myZip [1, 2] ['a', 'b', 'c'])