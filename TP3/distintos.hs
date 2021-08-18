-- Verificar se	todos os elementos	de	uma	lista são distintos.

achaDistinto :: Int -> [Int] -> Bool
achaDistinto b (a:c)
  | c==[] = if b == a then False else True
  | b == a = False
  | b /= a = achaDistinto b c 
  
distintos :: [Int] -> Bool
distintos (a:c)
  | c==[] = True
  | c/=[] = if achaDistinto a c then distintos c else False

main = print $ distintos [1,2,4,2,5]
