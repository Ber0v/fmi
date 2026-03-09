myAppend :: [a] -> [a] -> [a]
myAppend [] ys = ys
myAppend xs ys = xs ++ ys

main :: IO ()
main = do
  print (myAppend [1, 2, 3] [4, 5, 6])