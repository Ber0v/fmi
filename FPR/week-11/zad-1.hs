data IntTree
  = Empty
  | Node Int IntTree IntTree

andThenMaybe :: Maybe a -> (a -> Maybe b) -> Maybe b
andThenMaybe Nothing _ = Nothing
andThenMaybe (Just x) f = f x

andThenEither :: Either e a -> (a -> Either e b) -> Either e b
andThenEither (Left x) _ = Left x
andThenEither (Right x) f = f x