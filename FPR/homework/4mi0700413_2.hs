type RealFunction = Double -> Double
type Integrator = Int -> RealFunction -> Double -> Double -> Double

-- zad-1
interpolationNodes :: Int -> (Double, Double) -> [Double]
interpolationNodes n (a, b) =
  [a + h * fromIntegral i | i <- [0 .. n]]
  where
    h = (b - a) / fromIntegral n

-- zad-2
interpolationIntervals :: Int -> (Double, Double) -> [(Double, Double)]
interpolationIntervals n (a, b) =
  zip xs (tail xs)
  where
    xs = interpolationNodes n (a, b)

-- zad-3
data IntegralInfo = IntegralInfo RealFunction (Double, Double)

-- zad-4
quadRect :: Integrator
quadRect n f a b =
  sum [f mid * h | (x1, x2) <- intervals, let mid = (x1 + x2) / 2]
  where
    intervals = interpolationIntervals n (a, b)
    h = (b - a) / fromIntegral n

-- zad-5
quadTrap :: Integrator
quadTrap n f a b =
  sum [(f x1 + f x2) / 2 * h | (x1, x2) <- intervals]
  where
    intervals = interpolationIntervals n (a, b)
    h = (b - a) / fromIntegral n

--zad-6
quadSimpson :: Integrator
quadSimpson n f a b =
  sum [simpson x0 x1 x2 | (x0, x1, x2) <- triples]
  where
    n' = if even n then n else n + 1
    xs = interpolationNodes n' (a, b)
    triples = [(xs !! i, xs !! (i+1), xs !! (i+2)) | i <- [0,2..n'-2]]
    h = (b - a) / fromIntegral n'

    simpson x0 x1 x2 =
      (h / 3) * (f x0 + 4 * f x1 + f x2)

-- zad-7
data Uniform = Uniform Int
data Adaptive = Adaptive Double Int

-- zad-8
type Integrator' cfg = cfg -> RealFunction -> Double -> Double -> Double

-- zad-9
quadSimpsonAdaptive :: Integrator' Adaptive
quadSimpsonAdaptive (Adaptive eps maxD) f a b =
  simpsonAdaptive f a b eps maxD

simpsonAdaptive :: RealFunction -> Double -> Double -> Double -> Int -> Double
simpsonAdaptive f a b eps depth
  | depth == 0 = simpson f a b
  | abs (left + right - whole) < 15 * eps = left + right
  | otherwise =
      simpsonAdaptive f a m (eps / 2) (depth - 1) +
      simpsonAdaptive f m b (eps / 2) (depth - 1)
  where
    m = (a + b) / 2
    whole = simpson f a b
    left = simpson f a m
    right = simpson f m b

simpson :: RealFunction -> Double -> Double -> Double
simpson f a b =
  (b - a) / 6 * (f a + 4 * f m + f b)
  where
    m = (a + b) / 2

-- zad-10
data Method
  = Rectangle
  | Trapezoidal
  | SimpsonUniform
  | SimpsonAdaptive Adaptive

-- zad-11
refine :: Int -> Method -> IntegralInfo -> [Double]
refine step method (IntegralInfo f (a,b)) =
  case method of
    Rectangle -> map (\n -> quadRect n f a b) ns
    Trapezoidal -> map (\n -> quadTrap n f a b) ns
    SimpsonUniform -> map (\n -> quadSimpson n f a b) ns
    SimpsonAdaptive cfg -> repeat (quadSimpsonAdaptive cfg f a b)
  where
    ns = iterate (* step) 1

-- zad-12
convergesIn :: Int -> Double -> Int -> Method -> IntegralInfo -> Either () Int
convergesIn maxIter eps step method info =
  check 1 values
  where
    values = map apply ns
    ns = iterate (+ step) step

    apply n =
      case method of
        Rectangle -> useUniform quadRect n info
        Trapezoidal -> useUniform quadTrap n info
        SimpsonUniform -> useUniform quadSimpson n info
        SimpsonAdaptive cfg -> useAdaptive cfg info

    check i (x:y:xs)
      | abs (x - y) < eps && i == 1 = Right 1
      | i + 1 > maxIter = Left ()
      | abs (x - y) < eps = Right (i + 1)
      | otherwise = check (i + 1) (y:xs)

    check _ _ = Left ()

useUniform :: Integrator -> Int -> IntegralInfo -> Double
useUniform method n (IntegralInfo f (a,b)) =
  method n f a b
useAdaptive :: Adaptive -> IntegralInfo -> Double
useAdaptive cfg (IntegralInfo f (a,b)) =
  quadSimpsonAdaptive cfg f a b

-- zad-13
data SIIntervalTree
  = Leaf Double (Double, Double)
  | Branch Double (Double, Double) SIIntervalTree SIIntervalTree
  deriving Show

  -- zad-14
generate :: Adaptive -> IntegralInfo -> SIIntervalTree
generate (Adaptive eps depth) (IntegralInfo f (a,b)) =
  build f a b eps depth

build :: RealFunction -> Double -> Double -> Double -> Int -> SIIntervalTree
build f a b eps depth
  | depth == 0 = Leaf val (a,b)
  | abs (leftVal + rightVal - val) < 15 * eps =
      Branch val (a,b)
        (Leaf leftVal (a,m))
        (Leaf rightVal (m,b))
  | otherwise =
      Branch val (a,b)
        (build f a m (eps/2) (depth-1))
        (build f m b (eps/2) (depth-1))
  where
    m = (a + b) / 2
    val = simpson f a b
    leftVal = simpson f a m
    rightVal = simpson f m b

main :: IO ()
main = do
  putStrLn "Zadacha 1"
  print (interpolationNodes 4 (0, 1))
  putStrLn " "

  putStrLn "Zadacha 2"
  print (interpolationIntervals 4 (0, 1))
  putStrLn " "

  putStrLn "Zadacha 4"
  print (quadRect 4 abs (-1) 1)
  print (quadRect 4 (^2) 0 1)
  print (quadRect 100 (^2) 0 1)
  putStrLn " "

  putStrLn "Zadacha 5"
  print (quadTrap 4 abs (-1) 1)
  print (quadTrap 4 id 0 1)
  print (quadTrap 4 (^2) 0 1)
  putStrLn " "

  putStrLn "Zadacha 6"
  print (quadSimpson 4 abs (-1) 1)
  print (quadSimpson 4 id 0 1)
  print (quadSimpson 4 (^2) 0 1)
  putStrLn " "

  putStrLn "Zadacha 9"
  print (quadSimpsonAdaptive (Adaptive 1e-6 10) id 0 1)
  print (quadSimpsonAdaptive (Adaptive 1e-6 10) (^2) 0 1)
  print (quadSimpsonAdaptive (Adaptive 1e-14 10) sin 0 pi)
  putStrLn " "

  putStrLn "Zadacha 11"
  print (take 4 $ refine 2 Rectangle (IntegralInfo (^2) (0, 1)))
  print (take 4 $ refine 2 Trapezoidal (IntegralInfo (^2) (0, 1)))
  print (take 4 $ refine 2 SimpsonUniform (IntegralInfo (^2) (0, 1)))
  print (take 4 $ refine 2 (SimpsonAdaptive (Adaptive 1e-16 10)) (IntegralInfo (^2) (0, 1)))
  putStrLn " "

  putStrLn "Zadacha 12"
  print (convergesIn 20 1e-3 2 Rectangle (IntegralInfo (^2) (0, 1)))
  print (convergesIn 20 1e-5 2 Rectangle (IntegralInfo (^2) (0, 1)))
  print (convergesIn 20 1e-3 2 Trapezoidal (IntegralInfo (^2) (0, 1)))
  print (convergesIn 20 1e-5 2 Trapezoidal (IntegralInfo (^2) (0, 1)))
  print (convergesIn 30 1e-5 2 Trapezoidal (IntegralInfo (^2) (0, 1)))
  print (convergesIn 1 1e-16 2 SimpsonUniform (IntegralInfo (^2) (0, 1)))
  print (convergesIn 1 1e-16 2 (SimpsonAdaptive (Adaptive 1e-16 10)) (IntegralInfo (^2) (0, 1)))
  putStrLn " "

  putStrLn "Zadacha 14"
  print (generate (Adaptive 1e-18 20) (IntegralInfo (*2) (0, 1)))
  print (generate (Adaptive 1e-6 20) (IntegralInfo sin (0, 1)))