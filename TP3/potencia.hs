--Defina uma função recursiva para o cálculo de	potência de dois números inteiros,
-- onde o primeiro número é elevado ao segundo. Não se pode usar o operador de potência (^).

potencia :: Int->Int->Int
potencia a b
  | b > 0 = a*(potencia a (b-1))
  | b == 0 = 1

main = print $ potencia 2 3
