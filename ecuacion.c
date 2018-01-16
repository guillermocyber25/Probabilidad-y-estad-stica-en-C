// Motor para resolver ecuaciones 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float segundoFormula(float , float, float, float);

int main(){
	float a, b, c, tipo;
	//tipo valor 1 positivo 
	//valor 0 negativo
	printf("X = %f X = %f \n", segundoFormula(1 , 4 , 0, 1), segundoFormula(1 , 4 , 0, 0));

	return 0;	
}

float segundoFormula(float a, float b, float c, float tipo){
	float x;
    
	//desarrollo de la formula general
	// desarrollo negativo
	if(tipo){
		x = (((-b) + ( sqrt((pow(b, 2) - (4 * a * c) )) ))) / (2 * a);
		return x;
	}
	else{
		x = (((-b) - ( sqrt((pow(b, 2) - (4 * a * c) )) )) )/ (2 * a);
		return x;
	}
}
