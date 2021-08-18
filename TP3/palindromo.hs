-- Verificar se	uma	lista de inteiros é palíndromo.

inverte :: [Int] -> [Int]
inverte (a:x) = if x/=[] then inverte x ++ [a] -- troco os numeros
                       else [a]

achaPalindromo :: [Int] -> [Int] -> Bool
achaPalindromo (a:b) (c:d)
  | d == [] = if c == a then True else False                -- ultima iteração
  | d /= [] = if c == a then achaPalindromo b d else False  -- primeiras iterações, se for igual continua procurando até acabar

palindromo :: [Int] -> Bool
palindromo a = achaPalindromo a (inverte a)


main = print $ palindromo [1,2,3,4,3,2,1]
