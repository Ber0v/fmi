applyAll :: [a -> a] -> a -> a
applyAll [] x = x
applyAll (x : xs) y = x (applyAll xs y)

main :: IO ()
main = do
  print (applyAll [(+ 1), (* 2), (+ 3)] 5)