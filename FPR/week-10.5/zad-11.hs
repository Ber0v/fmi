rotateLeft :: IntTree -> IntTree
rotateLeft (Node x leftA (Node y leftB rightC)) =
    Node y (Node x leftA leftB) rightC
rotateLeft tree = tree

rotateRight :: IntTree -> IntTree
rotateRight (Node y (Node x leftA rightB) rightC) =
    Node x leftA (Node y rightB rightC)
rotateRight tree = tree