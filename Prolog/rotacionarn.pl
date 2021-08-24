inserirfim(A, [B | []], [B, A | []]).
inserirfim(A, [B | C], [B | D]) :- inserirfim(A, C, D).

rotacionar([], []).
rotacionar([A | B], L) :- inserirfim(A, B, L).

rotacionarn([], []).
rotacionarn(0, L, L).
rotacionarn(A, B, L) :- rotacionar(B, D), rotacionarn(E, D, L), A is E + 1.
