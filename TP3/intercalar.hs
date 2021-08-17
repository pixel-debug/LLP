-- Dadas duas listas ordenadas de forma	crescente, obter a lista ordenada resultante da intercalação delas.

intercalarListas ::[Int] -> [Int] -> [Int]
intercalarListas [] []= []
intercalarListas a [] = a
intercalarListas [] b = b

intercalarListas  (a:b) (x:y)
   | x <= a = [x] ++ intercalarListas (a:b) y
   | x >  a = [a] ++ intercalarListas (x:y) b

intercalar :: [Int] -> [Int] -> [Int]
intercalar a b = intercalarListas a b

main = print $ intercalar [1,5,10] [2,7,9,20,25]

