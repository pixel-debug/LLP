-- Função que retorna uma lista	com	a representação	em	binário	de	um número	inteiro.

binario :: Int -> [Int]
binario a
    | a /= 0 = [mod a 2] ++ binario (div a 2)   -- divisoes por 2
    | a <= 0 = []                               -- a <= 0 nao entra
  
inverteBinario :: [Int] -> [Int]
inverteBinario (a:x) = if x/=[] then inverteBinario x ++ [a] -- não ta vazia, troco os numeros
                       else [a]

main = print $ inverteBinario (binario 20)
