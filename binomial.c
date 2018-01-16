
// Guillermo Islas Arreola
//calculo de la probabilidad binomial

/*Definicion de variables
n = es el numero de eventos
x= es el numero de casos de exito
p = es el numero de proobabilidades
*/
/* funcion para calcular la distrubucion binomial
double bin(long k, long n, double p){
	
	if(0 == k)
	   return pow(1.0 - p, n);
	
	return((double)(n - k + 1) / k) * ((double)p / (1.0 - p)) * bin(k - 1, n , p);
}*/

#include <stdio.h>
#include <stdlib.h>

double factorial(int );
double comb(int, int);
double potencia(float, int);
double distBin(int, int, float);


int main(){

printf("%f\n",distBin(2,4,.8));

return 0;
}


// funcion para calcular el factorial
double factorial (int numero)
{
    if (numero <= 1) 
      return 1;
    else 
  	//se hace el calculo de forma recursiva
      return numero * factorial (numero - 1);
}

//funcion para calcular el numero de combinaciones
double comb(int n, int k){
	
	int combinaciones;

	combinaciones = factorial(n) / (factorial(n-k) * factorial(k));

    return combinaciones;

}

//funcion para calcular potencias
double potencia(float base, int exponente){

     int i; 
     float acu;

     acu = base;

     if(exponente >= 2)
        for(i = 0; i < exponente - 1; i++){
        acu *= base;
        }

     return acu;
}

double distBin(int x, int n, float p){

	float pmf;
    
	pmf = (comb(n, x) * potencia(p, x)) * potencia(1 - p, n - x);

	return pmf;  

}






