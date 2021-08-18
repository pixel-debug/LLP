-- Verificar se	uma	lista de inteiros é palíndromo.

inverte :: [Int] -> [Int]
inverte (a:x) = if x/=[] then inverte x ++ [a] -- troco os numeros
                       else [a]

palindromo :: [Int] -> Bool
palindromo a = a == inverte a


main = print $ palindromo [1,2,3,4,3,2,1]
