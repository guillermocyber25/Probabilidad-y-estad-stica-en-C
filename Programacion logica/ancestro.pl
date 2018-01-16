padre(valerio,guillermo).
padre(guillermo,memo).
padre(antonio,valerio).

ancestro(X,Z):-padre(X,Z).
ancestro(X,Z):-padre(X,R),ancestro(R,Z).
