
#include <stdlib.h>
#include  <stdio.h>

int main(){
    
    int n,i, cont=0;
    
    scanf("%d",&n);
  
    i=2;
    while(n > 1)
    {
        printf("contador = %d\n",cont++ );
       if(n % i == 0)
       {
          n=n/i;
          printf("FACTOR == %d\n",i );
          
          i=2;
       }
       else
          i++;

    }   
    

    return 0;
}