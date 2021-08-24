concatenar([], L, L).
concatenar([A | B], L, [A | C]) :- concatenar(B, L, C).

reverter([], []).
reverter([A | B], L) :- reverter(B, X), concatenar(X, [A], L).
