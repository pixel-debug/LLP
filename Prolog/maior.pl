maior([M], M).
maior([ A, B | C], M) :- A>B, maior([A | C), M).
maior([ A, B | C], M) :- maior([B | C], M).
