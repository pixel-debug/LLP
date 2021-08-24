nelementos([], 0).
nelementos([A | B], S) :- nelementos(B, C), S is C+1. 
