inserirfim(A, [B | []], [B, A | []]).
inserirfim(A, [B | C], [B | D]) :- inserirfim(A, C, D).

rotacionar([], []).
rotacionar([A | B], L) :- inserirfim(A, B, L).
