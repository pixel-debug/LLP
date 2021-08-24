remover(R, [R], []).
remover(R, [R | B], B).
remover(R, [A | B], C) :- remover(R, B, C).
remover(R, [A | B], [A | D]) :- remover(R, B, D).
