
imprime([X|[]]):-writeln(X).
imprime([X|Y]):-writeln(X),imprime(Y).