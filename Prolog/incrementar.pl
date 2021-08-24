incrementar([], []).
incrementar([A | B], [C | D]) :- C is A + 1, incrementar( B, D).
