-- Calcular	o somatório dos	elementos ímpares de uma lista de inteiros

somaImpares [] = 0
somaImpares (a:x) 
    | (mod a 2) ==0 = 0 + somaImpares x     -- par não soma
    | (mod a 2) == 1 = a + somaImpares x    -- impar soma

main = print $ somaImpares [1,3,2,7,4,6,5]
