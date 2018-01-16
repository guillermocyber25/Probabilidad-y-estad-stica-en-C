//calculo de la probabilidad binomial

/*Definicion de variables
n = es el numero de eventos
k= es el numero de casos de exito
p = es el numero de proobabilidades
*/
int factorial(int );
int comb(int, int);


int main(){
printf("%d\n",comb(5,3));
return 0;
}


// funcion para calcular el factorial
/*int factorial (int numero)
{
  if (numero <= 1) 
    return 1;
  else 
  	//se hace el calculo de forma recursiva
    return numero * factorial (numero - 1);
}*/

int comb(int n,int m)
{
if ((n==0) || (n==m)) return 1;
else return comb(n-1,m-1) + comb(n-1,m);
}

