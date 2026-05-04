import System.Win32 (xBUTTON1)

maximumBy' :: (a -> a -> Ordering) -> [a] -> a
maximumBy' _ [x] = x
maximumBy' f (x : xs)
  | f x (maximumBy' f xs) == GT = x
  | otherwise = maximumBy' f xs

main :: IO ()
main = do
  print (maximumBy' compare [3, 1, 4, 1, 5])
  print (maximumBy' (\x y -> compare (length x) (length y)) ["hi", "hello", "yo"])