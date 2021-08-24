gerar(A, A, [A | []]).
gerar(A, B, [A | L]) :- A < B, C is A + 1, gerar(C, B, L).
gerar(A, B, [A | L]) :- C is A - 1, gerar(C, B, L).
