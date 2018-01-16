#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
    int nivel;
    double Z;
}trust_level;

void intervalo_prop(int n, float p, float z){
    double me;// margen de error


    me = z * sqrt((p*(1 - p)) / n);

    printf("Margen de error es del %f por ciento\n", me*100);
    printf("Intervalo de confianza: %f y %f  \n", ((p - me)*100), ((p + me)*100));
}




int main(){
    trust_level tl;
    int n;
    float p,z;
    printf("Numero de eventos?\n");
    scanf("%d",&n);
    printf("proporcion de la muestra?\n");
    scanf("%f",&p);
    printf("introduce el nivel de confianza\n");
    scanf("%d", &tl.nivel);
    switch (tl.nivel){
    case 80:
        tl.Z=1.28;
        break;
    case 85:
        tl.Z=1.44;
        break;
    case 90:
        tl.Z=1.65;
        break;
    case 95:
        tl.Z=1.96;
        break;
    case 98:
        tl.Z=2.33;
        break;
    case 99:
        tl.Z=2.58;
        break;
    }
    z=tl.Z;

    intervalo_prop(n,p,z);

}
