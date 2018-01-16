#include <stdio.h>
#include <stdlib.h>

#define filas 3
#define columnas 3
#define matrices 3

#define entradas (filas * columnas)*matrices

void buble(int *[]);
void quicksort(int *[], int, int);
int busquedaBinaria(int *[], int, int);

int main(){

int array[3][3][3];
int i, j, z;
int index=0; // Indice para agregar las direcciones de memoria del arreglo

int *pointer[26]; 

int limite_izq = 0;
int limite_der = entradas-1;
	
	
	

srand(time(NULL));


printf("\n");

for(i = 0; i < matrices ; i++){
	for(j = 0; j < filas ; j++){
		for(z = 0; z < columnas ; z++){
			printf("[%d%d%d]", j, z, i);
			//printf("{%d}", index);
			
			
            
			//if(index < 26)
			pointer[index] = & array[j] [z] [i];
			array[j][z][i] = rand()%20;
			//if(index < 24)
			
			printf("[%d]",array[j][z][i]);
			index++;
            

		}
		printf("\n");
	}
	printf("\n");
}
printf("\n");


// se imprime sin ordenar

for(i = 0; i < entradas; i++){
	printf("-->%d\n",*pointer[i]);
}

printf("[%p]\n",  pointer[0]);

// DESCOMENTAR EL ORDENAMIENTO QUE SE QUIERE RELIZAR

//buble(pointer);
//quicksort(pointer, limite_izq, limite_der);

// una vez ordenado el arreglo se puede realizar la busqueda binaria
//printf("(%d)\n",busquedaBinaria(pointer, limite_der, 18));

for(i = 0; i < entradas; i++){
	printf("-->%d\n",*pointer[i]);
}
return 0;
}

void buble(int *pointer[]){

int i;
int j;
int aux;

for(i = 0; i < entradas-1; i++){
	for(j = entradas-1; j >= i+1; j--){
		
		if (*pointer[j] < *pointer[j-1]){
		aux = *pointer[j];
		*pointer[j] = *pointer[j - 1];
		*pointer[j - 1] = aux;
	}
	}
}


}


void quicksort(int *pointer[], int limite_izq, int limite_der)
{

    int izq,der,temporal,pivote;

 

    izq=limite_izq;
    der = limite_der;
    pivote = *pointer[(izq+der)/2];
 
    do{

        while(*pointer[izq] < pivote && izq < limite_der)izq++;
        while(pivote < *pointer[der] && der > limite_izq)der--;
        if(izq <=der)
        {
            temporal = *pointer[izq];
            *pointer[izq] = *pointer[der];
            *pointer[der] = temporal;
            izq++;
            der--;
 
        }
 
    }while(izq<=der);
    if(limite_izq<der){quicksort(pointer,limite_izq,der);}
    if(limite_der>izq){quicksort(pointer,izq,limite_der);}
 
}

int busquedaBinaria(int  *pointer[], int tam, int buscar) {
   
   int centro, inf = 0, sup = buscar-1;
   

   while(inf <= sup){
      centro = (sup + inf)/2;
      if(*pointer[centro] == buscar)       return centro;
      else 
      	if(buscar < *pointer[centro])  sup = centro-1;
      else                           inf = centro+1;
   }
   return -1;


}
