-- Desenvolver uma solução para	um quiosque	de saque eletrônico	que, para um determinado	valor,	
-- deve entregar o	menor número de	cédulas de	R$1,	R$5,	R$10,	R$50	e	R$100,	da	menor	para	a	maior.

fazTroca ::Int -> [Int]
fazTroca 0 = []
fazTroca  a
   | a >= 100 = fazTroca (a - 100)++[100]
   | a >= 50 = fazTroca (a - 50)++[50]
   | a >= 10 = fazTroca (a - 10)++[10]
   | a >= 5 = fazTroca (a - 5)++[5]
   | a >= 1 = fazTroca (a - 1)++[1]
   | otherwise = []

trocar :: Int -> [Int]
trocar a  = fazTroca a

main = print $ trocar 162
