%Recursividad

escNveces(X,1):-writeln(X).
escNveces(X,Y):-writeln(X),Z is Y-1,escNveces(X,Z).

numeros(1):-writeln(1).
numeros(X):-writeln(X),Z is X-1,numeros(Z).