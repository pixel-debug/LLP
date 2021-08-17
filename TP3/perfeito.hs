-- Verifique se	 um	 número é perfeito, isto é,  é	 igual a soma de seus
-- divisores (exceto o	próprio número).


perfeito :: Int -> Bool
perfeito a
  | achaPerfeito a [1, 2..] == a = True
  | achaPerfeito a [1, 2..] /= a = False
 

achaPerfeito :: Int -> [Int] ->Int
achaPerfeito b (c:d)
    | b == c = 0                            -- mesmo numero               
    | (mod b c ) == 0 = c + achaPerfeito b d    -- soma divisores  
    | (mod b c ) /= 0 = achaPerfeito b d        -- proximo numero 
    

main = print $ perfeito 28
