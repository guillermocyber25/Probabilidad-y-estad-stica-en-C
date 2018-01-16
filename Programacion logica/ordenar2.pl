%ORDENAMIENTO AL REVES


ord(X,Y,Z,[X|R]):-X>=Y,X>=Z,ord(Y,Z,R).
ord(X,Y,Z,[Y|R]):-Y>=X,Y>=Z,ord(X,Z,R).
ord(X,Y,Z,[Z|R]):-Z>=X,Z>=Y,ord(X,Y,R).
ord(X,Y,[X,Y]):-X>=Y.
ord(X,Y,[Y,X]).

%Regla para obtener el primero y el resto
primero(X,[X|_]).
resto(R,[_|R]).
%Regla para obtener el segundo
segundo(X,[_|[X|_]]).