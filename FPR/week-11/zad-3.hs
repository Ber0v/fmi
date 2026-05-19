collectResults :: [Maybe a] -> Maybe [a]
collectResults [] = Just []
collectResults (x : xs) = do
  value <- x
  rest <- collectResults xs
  Just (value : rest)

main :: IO ()
main = do
  print (collectResults [Just 1, Just 2, Just 3])
  print (collectResults [Just 1, Nothing, Just 3])