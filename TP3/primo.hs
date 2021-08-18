-- Verificar se	um	número é primo

achaPrimo :: Int -> [Int] ->Bool
achaPrimo b (c:d)
    | b < 2 = False                -- numeros iguais e menores que um não são primos
    | b == c = True                 -- igual 
    | (mod b c ) == 0 = False       -- modulo == 0
    | b /= c = achaPrimo b d        -- diferente, manda o 3 ..
    
primo :: Int -> Bool
primo a = achaPrimo a [2, 3 ..]

main = print $ primo 17
