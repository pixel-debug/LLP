-- Verificar se	um	número é primo

primo :: Int -> Bool
primo a = achaPrimo a [2, 3 ..]

achaPrimo :: Int -> [Int] ->Bool
achaPrimo b (c:d)
    | b <=1 = False
    | b == c = True                 -- igual 
    | (mod b c ) == 0 = False       -- modulo == 0
    | b /= c = achaPrimo b d        -- diferente, manda o 3 ..
    

main = print $ primo 17
