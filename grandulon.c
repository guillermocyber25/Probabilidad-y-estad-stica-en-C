#include <stdlib.h>
#include <stdio.h>

int main(){
	
    int array[5] = {5, 15, 7, 8, 9};
    int array2[4] = {0,0,0,0};
    int z = 0;
    int i = 0, j = 2;
    int r = 0 , aux;
    int mayor;
     srand(getpid());
    printf("Se cayo el cordinador\n");
   z = rand() % 5;
     printf("-->%d \n",array[z]);
   mayor = array[z];
    
    for(i = 0; i < 20; i ++){
    	if(z > 4)
    		z = 0;
    	if(r > 0)    		
    	if(array[z] > array2[r]){
    		array2[r] = array[z];
    		r++;
    		printf("%d\n", mayor);
    	}
    	else

    	z ++;
    }
    
    for(i = 0; i > r; i++){
    	printf("%d\n",array2[r]);
    }   
}