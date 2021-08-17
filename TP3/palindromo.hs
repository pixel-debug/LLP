-- Verificar se	uma	lista de inteiros é palíndromo.

achaPalindromo :: [Int] -> [Int] -> Bool
achaPalindromo (a:b) (c:d)
  | d == [] = if c == a then True else False                -- ultima iteração
  | d /= [] = if c == a then achaPalindromo b d else False  -- primeiras iterações, se for igual continua procurando até acabar

palindromo :: [Int] -> Bool
palindromo a = achaPalindromo a (corte a)

corte :: [Int] -> [Int]                                     -- corta a lista na metade
corte (a:d) = if d/=[] then corte d ++ [a] else [a]


main = print $ palindromo [1,2,3,4,3,2,1]
