-- Linearizar uma lista	de listas de inteiros.

linearizar :: [[Int]] -> [Int]
linearizar []=[]
linearizar (a:x) = a ++ linearizar x

main = print $ linearizar [ [1,2], [5], [0,4,2] ]
