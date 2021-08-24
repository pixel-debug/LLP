menor([M],M).
menor([A,B|X],M) :- B>A, menor([A|X],M).
menor([A,B|X],M) :- menor([B|X],M).

arrumalista([A|X],A,X).
arrumalista([A|X],B,[A|V]) :- arrumalista(X,B,V).

ordenar([],[]).
ordenar(A,[M|C]) :- menor(A,M), arrumalista(A, M, L), ordenar(L,C).

