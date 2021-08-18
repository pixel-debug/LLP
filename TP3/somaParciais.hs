-- Calcular	todas as somas	parciais de	uma	lista de inteiros.
  
soma :: Int -> Int
soma 1 = 1
soma x = soma (x - 1) + x

pegaSoma :: [Int] -> [Int]
pegaSoma [] = []
pegaSoma (a:x) = [soma a] ++ pegaSoma x


somaParciais :: [Int] -> [Int]
somaParciais x = pegaSoma x

main = print $ somaParciais [1,2,3,4]
-- [1, 3, 6, 10]
