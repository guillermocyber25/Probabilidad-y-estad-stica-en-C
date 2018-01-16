//algoritmo para resolver raiz cuadradrada de forma iterativa con su complejidad
// la complejidad de este algoritmo es  de complejidad k y se utiliza la apro

#include <stdio.h>
#include <stdlib.h>

float sqrIterativo(float);
void datos();

int main(){
datos();
return 0;

}

void datos(){
	float n;

	printf("Ingrese el numero para calcular la raiz cuadrada\n");
	scanf("%f",&n);

	printf("la raiz es == %f\n",sqrIterativo(n));

}
float sqrIterativo(float m)
{
    float i = 0;
    float x1 , x2;
    int j;
    printf("Principal x2 == 2	%f\n", m);
    
    //Se realiza una aproximacion a la base por medio de este ciclo
    while((i*i) <= m)
            i += 0.1;
    printf("%f\n",i);
    x1 = i;
    
    for(j=0;j<10;j++)
    {
        x2 = m;
        printf("1 x2 == m%f\n", x2);
        x2 /= x1;
        printf("2 x2 == %f\n", x2);

        x2 += x1;
         printf("3 x2 == %f\n", x1);
        x2 /= 2;
        printf("4 x2 == %f\n", x2);
        x1 = x2;
        printf("5 x1 == %f\n", x1);
        printf("\n");
    }

    return x2;
}

