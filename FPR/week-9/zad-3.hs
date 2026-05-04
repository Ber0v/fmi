firstJust :: [Maybe a] -> Maybe a
firstJust [] = Nothing
firstJust (x:xs) =
  case x of
    Just v -> Just v
    Nothing -> firstJust xs

main :: IO ()
main = do
  print (firstJust [Just 1, Just 2, Just 3])
  print (firstJust [Just 1, Nothing, Just 3])