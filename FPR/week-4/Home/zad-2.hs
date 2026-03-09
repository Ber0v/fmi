rotateLeft :: Int -> [a] -> [a]
rotateRight :: Int -> [a] -> [a]
rotateLeft n xs = drop n xs ++ take n xs

rotateRight n xs = rotateLeft (length xs - n) xs

main :: IO ()
main = do
  print (rotateLeft 2 [1, 2, 3, 4])
  print (rotateRight 2 [1, 2, 3, 4])