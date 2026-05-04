data Tree a = Empty | Node (Tree a) a (Tree a)

inorder :: Tree a -> [a]
inorder (Node l x r) = inorder l ++ [x] ++ inorder r

preorder :: Tree a -> [a]
preorder (Node l x r) = [x] ++ preorder l ++ preorder r

postorder :: Tree a -> [a]
postorder (Node l x r) = postorder l ++ postorder r ++ [x]