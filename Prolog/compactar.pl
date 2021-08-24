compactar([], []).
compactar([A|[]], [[1, A | []]|[]]).
compactar([A, A | B], [[D,A | []] | E]) :- compactar([A | B], [[ F, A | []] | E]), D is F +1.
compactar([A, B | C], [[1,A | []] | E]) :- compactar([B | C], E).
