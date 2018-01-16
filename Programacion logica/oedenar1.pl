% hecho ord(3,5,1,R)

%regla

ord(X,Y,Z,[X|R]):-X=<Y,X=<Z,ord(Y,Z,R).
ord(X,Y,Z,[Y|R]):-Y=<X,Y=<Z,ord(X,Z,R).
ord(X,Y,Z,[Z|R]):-Z=<X,Z=<Y,ord(X,Y,R).
ord(X,Y,[X,Y]):-X=<Y.
ord(X,Y,[Y,X]).
