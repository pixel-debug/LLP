tamanho([], 0).
tamanho([A | B], S) :- tamanho(B, C), S is C+1.

soma([], 0).
soma([A | B], S) :- soma(B, C), S is A + C.

medio([], 0).
medio(A, M) :- soma(A, S), tamanho(A, T), M is S/T.
