-- Linearizar uma lista	de listas de inteiros.


juntaListas :: [[Int]] -> [Int]
juntaListas (a:b)
    | b == [] = a
    | b /= [] = a ++ juntaListas b

linearizar :: [[Int]] -> [Int]
linearizar a = juntaListas a

main = print $ linearizar [ [1,2], [5], [0,4,2] ]
