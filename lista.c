//stack
//cola

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{ 
	int valor;
	struct lista *sig;	
}Lista;

typedef struct lista2
{
	int valor;
	struct lista2 *next;
	struct lista2 *prev;
}ListaD;

static ListaD *listDouble;

void listaDoble();
void push(Lista **, int num);
int main(){
	Lista *lista;
    lista = NULL;
    
    push(&lista, 6);
    push(&lista, 5);
    push(&lista, 4);
    push(&lista, 3);
    push(&lista, 7);
    push(&lista, 3);
    push(&lista, 88);
    push(&lista, 6);
    push(&lista, 33);
    push(&lista, 11);
    push(&lista, 6);
    push(&lista, 6);    

    while(lista != NULL){
    	printf("%d\n", lista -> valor);
    	lista = lista -> sig;
    } 
    printf("\n");
    listaDoble();
    return 0;
}



void push(Lista **lista, int num){
  
  Lista **head, *body, *aux;
  
  if(*lista == NULL){
  	head = lista;
  	
  	(*head) = (Lista *) malloc (sizeof(Lista));
   	(*head) -> valor = num;
   	(*head) -> sig = NULL;
    body = (*head); 
    } 
  else{
  	if(body -> sig == NULL)
    {
    body -> sig = (Lista *) malloc (sizeof(Lista));
    body =  body -> sig;
    body -> valor = num;
    body -> sig = NULL;
    }
  else{
  	while(body != NULL){
  		aux = body;
  		body = body -> sig;
  	}
    aux -> sig = (Lista *) malloc (sizeof(Lista));
    aux = aux -> sig;
    aux -> valor = num;
    aux -> sig = NULL;
  }   
  } 
}

