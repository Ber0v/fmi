type FileSystem = [(String, Either String [(String, String)])]

safePath :: FileSystem -> [String] -> Maybe String
safePath _ [] = Nothing
safePath fs [file] = do
  entry <- lookup file fs

  case entry of
    Left content -> Just content
    Right _ -> Nothing
safePath fs (dir : rest) = do
  entry <- lookup dir fs

  case entry of
    Left _ -> Nothing
    Right subdirs ->
      safePath (map (\(name, content) -> (name, Left content)) subdirs) rest