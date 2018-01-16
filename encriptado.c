
/**
PROGRAMA DE ENCRIPTACION DE MENSAJES
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASII 127;
void leeArchivo(char []);
void encripta(char [], char [], int);
int main(){
    //FILE *archivo;
    char cadena [100];   
	fflush(stdin);
	char key[] = {"Key\0"};
    
    
	int longitud;
	
	leeArchivo(cadena);
	
    longitud = strlen(cadena);

    encripta(cadena, key, longitud);
    
    //printf("longitud == (%d)\n", longitud);
    
    //printf("%s\n",cadena);
    
	return 0;
}

void leeArchivo(char cadena[]){

	FILE *archivo;
    
	//scanf("%s",cadena);

	/**lectura desde archivo de texto**/
    archivo = fopen ( "texto.txt", "r" );
    
    if (archivo == NULL)
 		exit(1);

    while (feof(archivo) == 0)
 	{
 		fgets(cadena,100,archivo);
 	}
 	
 
 	fclose ( archivo );
}

void encripta(char cadena[], char key[], int longitud){
	int lk, i, tamkey = 3;
	int lc, j, z;
	int cont = 0;
	int pueba;
	char pru;
	char pru2;
	char encripta[longitud];
	char llave[3];
	char c;
	int c2;

	lk = strlen(key); //se determina la longitud de la llave
    lc = strlen(cadena); // se determina la longitud de la cadena
    
    
    for(i = 0; i < longitud; i++){
        
        if(cont == 3)
        	cont = 0;
        printf("key == [%d,(%c)] cadena[%d,(%c)]\n", cont, key[cont], i, cadena[i]);
    	encripta[i] = (cadena[i] ^ key[cont]);
    	printf("resultado == %d\n",encripta[i]);
        cont++;
    }
    
    for(i = 0; i < longitud; i++){
        printf("(%i)", encripta[i]);
        if(i % 10 == 0)
        	printf("\n");
        
    }

    pru = (cadena[3] ^ key[0]);

    pru2 = (pru ^ key[0]);
    
    cont = 0;
    //algoritmo para desencriptar mensaje
    for(i = 0; i < 5; i++){
        //for(j = 0; j <5; j++){
            for(z = 1; z <= 127; z++){
               c = z;
               if((encripta[i] ^ c) == cadena[i]){
               	if(cont < 4)
               	{	
               	llave[cont] = (cadena[i] ^ encripta[i]);
               	cont++;
                }
               	printf("%c",(cadena[i] ^ encripta[i]));
               }
          //  }	
        }
        printf("\n");
    }

     
    
    
    //printf("\nASII == %i  caracter = %c \n", pru, pru);
	//printf("ASII == %x  caracter = %c \n", pru2, pru2);
	
}
