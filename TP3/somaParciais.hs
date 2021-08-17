-- Calcular	todas as somas	parciais de	uma	lista de inteiros.
  

inverteSoma :: [Int] -> [Int]
inverteSoma (a:x) = if x/=[] then inverteSoma x ++ [a] 
                       else [a]

soma :: [Int] -> Int
soma (a:x) = if x /= [] then a + soma x else a

pegaSoma :: [Int] -> [Int]
pegaSoma (a:x)
  | x /= [] = [(a + soma x)] ++ pegaSoma x
  | x == [] = [a]

somaParciais :: [Int] -> [Int]
somaParciais x = inverteSoma(pegaSoma(inverteSoma x))

main = print $ somaParciais [1,2,3,4]
-- [1, 3, 6, 10]
