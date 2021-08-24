ultimo([], 0).
ultimo([A | []], A).
ultimo([A | B], U) :- ultimo(B, U).
