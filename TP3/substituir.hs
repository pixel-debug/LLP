-- Substituir todos	 elementos	de um determinado valor de uma lista de inteiros	por	um	outro	valor

substituir :: Int->Int->[Int]->[Int]
substituir a b (x:y) 
    | a == x = [b] ++ (if y/=[] then substituir a b y else [])
    | otherwise = [x] ++ (if y/=[] then substituir a b y else [])
main = print $ substituir 1 0 [1,2,1,3,1] 
