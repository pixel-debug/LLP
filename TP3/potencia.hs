--Defina uma função recursiva para o cálculo de	potência de dois números inteiros,
-- onde o primeiro número é elevado ao segundo. Não se pode usar o operador de potência (^).

potencia :: Int->Int->Int
potencia b 0 = 1
potencia b e = b * potencia b (e-1)

main = print $ potencia 2 3
