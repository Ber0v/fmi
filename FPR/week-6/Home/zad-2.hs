encode :: (Eq a) => [a] -> [(Int, a)]
encode [] = []
encode (x : xs) =
  (1 + length same, x) : encode rest
  where
    same = takeWhile (== x) xs
    rest = dropWhile (== x) xs

decode :: [(Int, a)] -> [a]
decode [] = []
decode ((x, y) : xs) = replicate x y ++ decode xs

main :: IO ()
main = do
  print (encode "aaaabcca")
  print (decode [(4, 'a'), (1, 'b'), (2, 'c'), (2, 'a')])