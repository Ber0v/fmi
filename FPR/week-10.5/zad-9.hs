isSymmetric :: IntTree -> Bool
isSymmetric Empty = True
isSymmetric (Node _ left right) = mirror left right

mirror :: IntTree -> IntTree -> Bool
mirror Empty Empty = True
mirror (Node v1 l1 r1) (Node v2 l2 r2) =
    v1 == v2 && mirror l1 r2 && mirror r1 l2
mirror _ _ = False