-- Deslocar todos elementos	de uma lista de inteiros k posições para a esquerda

shiftLeft :: Int -> [Int] -> [Int]
shiftLeft 0 b = b
shiftLeft a (c:b) = (shiftLeft (a - 1) (b ++ [c]))  -- pega os elementos daquela posição pra baixo e coloca no final

shift :: Int -> [Int] -> [Int]
shift a b = shiftLeft a b

main = print $ shift 3 [1,5,6,7,3,4,1]
