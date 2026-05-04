histogram :: String -> [(Char, Int)]
histogram [] = []
histogram (x:xs) =
    (x, 1+length same) : histogram rest
    where
        same =[y| y <-xs,y==x]
        rest = [y| y <-xs,y/=x]

main :: IO ()
main = do
  print (histogram "hello")