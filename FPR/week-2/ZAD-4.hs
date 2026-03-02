isWeekend :: Int -> Bool
isWeekend 1 = False
isWeekend 2 = False
isWeekend 3 = False
isWeekend 4 = False
isWeekend 5 = False
isWeekend 6 = True
isWeekend 7 = True

main :: IO()
main = do
    print(isWeekend 6)
    print(isWeekend 3)