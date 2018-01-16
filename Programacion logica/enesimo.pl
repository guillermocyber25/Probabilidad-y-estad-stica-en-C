%Tarea Logica y programacion logica 07/10/2014
%Ordenar numeros de una lista

% X Elemento a encontrar
% Y Enesimo elemento de la lista
% R La lista se va ir divividiendo en primero y resto, para que cuando la recursividad termine el primero sea el enesimo termino
% Devido a que el resto es una lista este es el que se va ir actualizando por lo tanto cuando el enesimo llegue a uno el primero sera el elemnto a encontrar


enesimo([X|_],1,X).
enesimo([_|R],Y,X):-Z is Y-1, enesimo(R,Z,X).