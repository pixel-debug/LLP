adjacente(A, B,[A|[B|_]]):-!.
adjacente(A, B, [_|M]):-adjacente(A, B, M).

