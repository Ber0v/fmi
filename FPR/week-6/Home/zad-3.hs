type Matrix = [[Int]]

matrixMultiply :: Matrix -> Matrix -> Matrix
matrixMultiply a b =
  [ [sum (zipWith (*) row col) | col <- transpose b]
    | row <- a
  ]

transpose :: Matrix -> Matrix
transpose ([] : _) = []
transpose x = map head x : transpose (map tail x)

main :: IO ()
main = do
  print (matrixMultiply [[1, 2], [3, 4]] [[5, 6], [7, 8]])