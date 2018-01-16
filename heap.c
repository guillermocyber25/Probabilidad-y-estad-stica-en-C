// la complejidad del ordenamiento heap sort o de monticulos binomiales es nlogn

#include <stdlib.h>
#include <stdio.h>

void creaHeap(int *, int);
void heapsort(int *, int, int);

int main()
{
 int arr[1000]; 
 int i , j, tam, z, k;

 
 
 printf("\n\t        Heap Sort           \n\n");
 printf("Ingrese la longitud del arreglo:");
 scanf("%d", & tam);
 
 for(i = 1; i <= tam; i++)
 {
   arr[i] = rand() % 11 + 20;
   creaHeap(arr, i);
 }
 j = tam;
 for(i = 1; i <= j; i++)
 {
   z = arr[1];
   arr[1] = arr[tam];
   arr[tam] = z;
   tam--;
   heapsort(arr, 1, tam);
 }
 printf("\n\t------- Elementos Ordenados-------\n\n");
 tam = j;
 for(i = 1; i <= tam; i++)
     printf("%d ", arr[i]);
 
 printf("\n");
 return 0;
}


void creaHeap(int *arr, int i)
{
 int z; 
 z = arr[i];
 while((i > 1) && (arr[i/2] < z))
 {
    printf("%d,%d\n",arr[i], arr[i/2]);
   arr[i] = arr[i / 2];

   i = i / 2;
 }
 arr[i] = z;
 printf("%d\n", arr[i]);
 printf("\n");

}


void heapsort(int *arr, int i, int tam)
{
 int z,j;
 z=arr[i];
 j=i*2;
 while(j<=tam)
 {
   if((j<tam)&&(arr[j]<arr[j+1])){
      printf("%d,%d\n",arr[j], arr[j+1]);
      j++;}
   if(arr[j]<arr[j/2]){
      printf("%d,%d\n",arr[j], arr[j/2]);
      break;}
   arr[j/2]=arr[j];
   j=j*2;
 }
 arr[j/2]=z;
 printf("%d\n",arr[j/2]);
 printf("\n");
}
