#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc,char* argv[]) {

        time_t inicio,fin;
  char texto_teclado [50];
  double diferencia;
  long int relojj = clock();
  printf("%li\n",relojj );
  time (&inicio);
  sleep(10);
  time (&fin);
  //diferencia = difftime (fin,inicio);
  diferencia = fin - inicio;
  printf ("Hola %s.\n", texto_teclado);
  printf ("Levouche %.2f segundos escribir o teu nome.\n", diferencia );
}