#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Se define la constante euller


//Funcion para calcular la distribucion binomial
double b(long k, long n, double p){
    if ( k == 0) return pow(1.0 - p, n);
    return ( (double)(n - k + 1) / k * p / (1.0 - p) ) * b(k - 1, n, p);
}

void printfBinomial(long n){
    euller =
    long i = 0, col = 0;
    double binomial[14]={0};
    double array[14]={.01, .05, .10, .20, .25, .30, .40,
                      .50, .60, .70, .75, .80, .90, .95};
    
    printf(" ");
    printf("p  | ");
    
    //se tiene el ciclo para imprimir los intervalos

    for(i = 0; i != 14; i++){ 
       printf("%.3f ", array[i]);
    }
    
    printf("\n");
    printf("\n");
    
    //Ciclo que genera la tabla de distribucion acumulada a partir de n
    while (col != n+1){
        printf(" ");
        if (col<10)
            printf("%lu  | ",col );
        else    
            printf("%lu | ",col );
        for(i = 0; i != 14; i++){ 
            binomial[i] +=  b(col,n,array[i]); 
            printf("%.3f ",binomial[i]); 
        }
        col++;
        printf("\n");
    }
}

int main(){
    int n;

    printf("Ingrese el valor de n \n");
    scanf("%d",&n);
    printf("\n");

    printfBinomial(n);
	return 0;
}
