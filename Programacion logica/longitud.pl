longitud([_|[]],1).
longitud([_|Y],X):-longitud(Y,Z),X is Z+1.

