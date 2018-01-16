#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double valorZ(int porcentaje){
	
	double z;

	switch(porcentaje){
	     case 80: z = 1.28;
	     break;

	     case 85: z = 1.44;
	     break;

	     case 90: z = 1.65;
	     break;

	     case 95: z = 1.96;
	     break;

	     case 98: z = 2.33;
	     break;

	     case 99: z = 2.58;
	     break;

	     default: {
	     	      printf("Los valores deben ser 80, 85, 90, 95, 98, 99\n");     
                  exit(1);
         }         
	} 
	return z;
}

void printIntervalo(int nConfianza, double p, double n){

	double error;// margen de error
    double z;

    
    z = valorZ(nConfianza);
    
    error = z * sqrt((p*(1 - p)) / n);

    printf("El margen de error es del %.2f por ciento\n", error*100);
    printf("el intervalo de confianza esta entre %.2f y %.2f por ciento\n", ((p - error)*100), ((p + error)*100));
}

int main(){
    
    int nConfianza;
    double p;
    double n;
    


    printf("Nivel de confianza->");
    scanf("%d",& nConfianza);

    printf("Proporcion de la muestra->");
    scanf("%la",& p);
    
    printf("numero de eventos->");
    scanf("%la",& n);
    
	printIntervalo(nConfianza, p, n);
    
	return 0;
}

