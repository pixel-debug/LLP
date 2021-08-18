-- Função que retorna uma lista	com	a representação	em	binário	de	um número	inteiro.

binario :: Int -> [Int]
binario a
    | a == 0 = [0]                                                        -- coloco 0 
    | a == 1 = [1]                                                        -- coloco 1 
    | otherwise =  binario (div a 2 ) ++ [mod a 2]                        -- faço a conta
  
inverteBinario :: [Int] -> [Int]

main = print $ binario 20
