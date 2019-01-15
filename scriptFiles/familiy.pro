mutter(luisa, odo).
mutter(lenny, roman).
vater(roman, odo).
vater(leonardo, roman).


grossvater(X, Y) :- (vater(X, Z), vater(Z, Y)); (vater(X, Z), mutter(Z, Y)).
grossmutter(X, Y) :- (mutter(X, Z), vater(Z, Y)); (mutter(X, Z), mutter(Z, Y)).