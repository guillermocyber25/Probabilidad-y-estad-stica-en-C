//normal invertido
//variable aletaroria discreta| funcion de probabilidad y distribucion

#include <stdio.h>
#include <math.h>

#define e 2.7183 //Se define la constante de euller
#define ep 0.0001
//declaracion de prototipos
double poisson(long int, double);
void printPoison(float);

int main(){

   long a;
   float b;

   scanf("%f",& b);
   printPoison(b);

   
   return 0;
}


//funcion poisson
double poisson(long x, double k){
	
	if(x == 0)
	   return pow(e, -k);
	
	return ((double)(k / x) * poisson(x - 1, k));
}

void printPoison(float p){
   
    long i=0;
    int j;
	float acu[10]={0}; // es para hacer el acumulado
    float pin = p;
	printf("    ");
	for(j = 0; j < 10; j++){ 
       printf("%.4f|", p);
       p += .1;
	}
	printf(" x");
	
	
	printf("\n");
	printf("\n");
    i = 0;
	//for(i = 0; i != x + 1; i++){
	while(acu[9] <= 1-ep){
        printf("   |");
        p = pin;
        for(j = 0; j < 10; j++){
            acu[j] += poisson(i, p);
            printf("%.4f|", acu[j]);        
         p += .10;
         }
         i++;
        printf("<-%lu", i-1); 
        printf("\n");
         //printf("(%f)",acu);
    }
      
}
