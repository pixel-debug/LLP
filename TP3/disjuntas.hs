-- Verificar se	duas listas	são	disjuntas ( não tem elementos em comum).

achaDisjunta :: Int -> [Int] -> Bool
achaDisjunta b (a:c)
  | c == [] = if b == a then True else False
  | c /= [] = if b == a then True else achaDisjunta b c

disjuntas :: [Int] -> [Int] -> Bool
disjuntas d (a:c)
  | c==[] = if achaDisjunta a d then True else False
  | c/=[] = if achaDisjunta a d then True else disjuntas c d

main = print $ disjuntas [1,2,3] [5,1,6,0]
