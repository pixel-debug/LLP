-- Remover os n últimos	elementos de uma lista de inteiros.
 --Ex.: > removerFim 2 [1,2,3,4,5,6] -- n=2
-- [1,2,3,4]

remover :: Int -> [Int] -> [Int]
remover 0 b = b
remover a (c:b) = remover (a - 1) b  -- tira os primeiros

inverte :: [Int] -> [Int]
inverte (a:x) = if x/=[] then inverte x ++ [a] else [a]

removerFim :: Int -> [Int] -> [Int]
removerFim a b = inverte (remover a( inverte b))        -- inverte os primeiros com os ultimos e tira eles

main = print $ removerFim 2 [1,2,3,4,5,6] 
