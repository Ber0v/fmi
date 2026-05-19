{- HLINT ignore "Eta reduce" -}
data FamilyTree
  = Person String [FamilyTree]
  deriving (Show)

maxGeneration :: FamilyTree -> Int
maxGeneration (Person _ []) = 1
maxGeneration (Person _ children) =
  1 + maximum (map maxGeneration children)

noChildren :: FamilyTree -> [String]
noChildren (Person name []) = [name]
noChildren (Person _ children) =
  concatMap noChildren children

bigFamily :: Int -> FamilyTree -> [String]
bigFamily n tree = helper 1 tree
  where
    helper level (Person name children)
      | level > n = name : concatMap (helper (level + 1)) children
      | otherwise = concatMap (helper (level + 1)) children

type Relation = (String, String)

hasCycle :: [Relation] -> Bool
hasCycle relations =
  any (\(a, b) -> (b, a) `elem` relations) relations