linearizar([], []).
linearizar([[A | B] | C], [A | D]) :- linearizar([B | C], D).
linearizar([[A | []] | B], [A | C]) :- linearizar(B, C).
