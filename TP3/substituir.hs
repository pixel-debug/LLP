-- Substituir todos	 elementos	de um determinado valor de uma lista de inteiros	por	um	outro	valor

substituir :: Int -> Int -> [Int] -> [Int]
substituir a b [] = []
substituir a b (x:y)
    | a == x = [b] ++ substituir a b y
    | otherwise = [x] ++ substituir a b y


main = print $ substituir 1 0 [1,2,1,3,1] 
