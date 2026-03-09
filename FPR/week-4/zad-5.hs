removeAt :: Int -> [a] -> [a]
removeAt n xs = take (n - 1) xs ++ drop n xs

main :: IO ()
main = do
  print (removeAt 2 [1, 2, 3, 4])