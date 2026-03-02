clasified :: (String, Int, String, Int) -> String
clasified (tip, white, destination, priority)
    | white < 0 = "Error"
    | tip == "food" && white < 500 = "Specialen hladilen"
    | tip == "chemicals" && destination /= "Bulgaria" = "Opasen Mezdunaroden"
    | tip == "electrinics" && (white > 1 && white < 10) && destination /= "Sofia" = "Chupliva tehnika"
    | otherwise = "standart"

main :: IO()
main = do 
    print(clasified ("food", 250, "Sofia", 8))
    print(clasified ("chemicals", 25, "Ungaria", 5))
    print(clasified ("electrinics", 5, "Moskva", 6))
    print(clasified ("hi", 250, "Sofia", 8))