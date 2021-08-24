inserirfim(0, [], []).
inserirfim(A, [B | []], [B, A | []]).
inserirfim(A, [], [A | []]).
inserirfim(A, [B | C], [B | D]) :- inserirfim(A, C, D). 


