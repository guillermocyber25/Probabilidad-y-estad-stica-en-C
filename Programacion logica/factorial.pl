%Factorial

factorial(1,1). 
factorial(N,X):-A is N-1,factorial(A,Z),X is N*Z. 