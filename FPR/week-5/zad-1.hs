myMap :: (a -> b) -> [a] -> [b]
myMap f [] = []
myMap f (x : xs) = f x : myMap f xs

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter f [] = []
myFilter f (x : xs)
  | f x = x : myFilter f xs
  | otherwise = myFilter f xs

main :: IO ()
main = do
  print (myMap (* 2) [1, 2, 3, 4])
  print (myFilter even [1, 2, 3, 4])