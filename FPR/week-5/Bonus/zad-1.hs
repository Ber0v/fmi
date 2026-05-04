incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy [] _ = []
incrementAllBy (x : xs) n = (x + n) : incrementAllBy xs n

main :: IO ()
main = do
  print (incrementAllBy [1, 2, 3, 4] 2)