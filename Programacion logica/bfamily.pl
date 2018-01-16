
	padre(terach,abraham).			hombre(terach).
	padre(terach,nachor).			hombre(abraham).
	padre(terach,haran).			hombre(nachor).
	padre(abraham,isaac).			hombre(haran).
	padre(haran,lot).			    hombre(isaac).
	padre(haran,milcah).			hombre(lot).
	padre(haran,yiscah).

						            mujer(sarah).
	madre(sarah,isaac).			    mujer(milcah).
						            mujer(yiscah).
	% En este caso X es el padre Y y J son las posibles hijas y se hace la comparacion para determinar que son mujeres
	
	hermano(X,Y):-padre(Z,X),padre(Z,Y),X \== Y.						
    
	hija(A,B):-padre(B,A),mujer(A).
	
%	Program 1.1: A biblical family database
