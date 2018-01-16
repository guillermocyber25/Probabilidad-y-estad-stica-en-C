%relacion de padres e hijos en este caso el padre es el abuelo

madre(ruperta,maribel).
madre(ruperta,tono).
madre(ruperta,irma).
madre(ruperta,raul).
madre(ruperta,hugo).
madre(ruperta,guillermina).

%relacion padres e hijos en este caso el hijo es el nieto y padrinos

padre(tono,erick).                 padrino(tono,paola).
padre(tono,darvely).               padrino(raul,luis).
padre(raul,nancy).                 padrino(hugo,nancy).
padre(raul,miguel).
padre(raul,vanesa).
padre(hugo,paola).


madre(maribel,memo).
madre(maribel,roxana).
madre(guillermina,luis).
madre(guillermina,fernanda).

%relacion de esposos

esposos(maribel,guillermo).
esposos(tono,veronica).
esposos(irma,manuel).
esposos(raul,maria).
esposos(hugo,clarisa).
esposos(guillermina,alejandro).
esposos(ruperta,antonio).

%base de datos por sexo

femenino(maribel).            masculino(tono).         
femenino(veronica).           masculino(guillermo).
femenino(maria).              masculino(memo).
femenino(clarisa).            masculino(raul).
femenino(guillermina).        masculino(hugo).
femenino(ruperta).            masculino(erick).
femenino(roxana).             masculino(darvely).
femenino(fernanda).           masculino(miguel).
femenino(vanesa).             masculino(antonio).
femenino(nancy).              masculino(alejandro).
femenino(paola).              
femenino(irma). 

%https://omegaup.com/problem/list/              

%reglas hermano sobrino suegra cuñado nuera

hermano(X,Y):-madre(Z,X),madre(Z,Y),dif(X,Y).
hermano(X,Y):-padre(Z,X),padre(Z,Y),dif(X,Y).Z).

cunado(X,Y):-esposos(Z,X),hermano(Z,Y).

nuera(Y,X):-esposos(Z,Y),madre(X,Z),femenino(Y).

primos(X,Y):-padre(Z,X),padre(J,Y),hermano(Z,J).

compadre(X,Y):-padrino(X,Z),padre(Y,Z).