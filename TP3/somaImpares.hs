-- Calcular	o somatório dos	elementos ímpares de uma lista de inteiros

somaImpares [] = 0
somaImpares (a:x) = if (mod a 2)/=0 then a + somaImpares x else 0 + somaImpares x

main = print $ somaImpares [1,3,2,7,4,6,5]
