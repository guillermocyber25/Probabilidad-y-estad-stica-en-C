#include <stdlib.h>
#include <stdio.h>

int main(){

	int array[999], arrayF[999];
    int tam, i, j, cont = 0, cont2 = 0, cont3 = 0, menor = 0;
 
    scanf("%d", & tam);
    
    for(i = 0; i != tam; i++){
    	scanf("%d", & array[i]);
    }

    for(i = 0; i != tam-1; i++){
    	printf("[%d] = %d\n", i, array[i]);
    	
    	if(array[i] >= array[i  + 1]){
    	    arrayF[i] = array[i] - array[i+1];
    	    cont++;
    	}
        else{
        	arrayF[i] = array[i+1] - array[i];
        	cont++;
        }
    	printf("arrayF[%d] = %d\n", i, arrayF[i]);
    }
    printf("%d\n", cont);
    
  
    for(i = 1; i < tam + 1; i++){
    	for(j = 0; j < cont; j++){
    		printf("INDICE == %d\n",i);
    		if(arrayF[j] == i){
    			
    			printf("indice = %d arrayF[%d] = %d \n", i, j, arrayF[j]);
    			cont2 ++;
    			printf("CONT2 == %d\n",cont2 );
    		}
    	}
    	if(cont2 > 0){
    		cont3 ++;
    	}
    	else{
    		if(menor == 0)
               menor = i;
    		if(i < menor)
    			menor = i;
    	}
    	cont2 = 0;
    	//printf("SI\n");
    }
    	
    
    if(cont3 == tam - 1)
    	printf("EL RESULTADO ES == %d\n",0);
    else
    	printf("EL RESULTADO ES == %d\n",menor);
    return 0;

}