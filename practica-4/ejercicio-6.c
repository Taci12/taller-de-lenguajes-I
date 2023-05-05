#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct l
{
  struct l *siguiente;
  int dato;
};

typedef struct l nodo;

void iniciarLista(nodo **);
void agregarInicio(nodo **, int dato);
void imprimirLista(nodo *);
void agregarFinal(nodo **, int dato);
int cantidad_elementos(nodo *lista);

int main()
{
  nodo *lista; // defino la lista
  iniciarLista(&lista);
  agregarInicio(&lista, 1);
  agregarInicio(&lista, 4);
  agregarInicio(&lista, 8);
  // lista -> 8 -> 4 -> 1
  imprimirLista(lista);
  int cantidad;
  cantidad = cantidad_elementos(lista);
  agregarFinal(&lista, 9);
  // lista -> 8 -> 4 -> 1 -> 9
  printf("cantidad de elementos: %d\n", cantidad);
  imprimirLista(lista);
  eliminarLista(&lista);
  imprimirLista(lista);
  return 0;
}

void iniciarLista(nodo **lista)
{
  *lista = NULL;
}

void agregarInicio(nodo **lista, int dato)
{
  nodo *nuevo;
  nuevo = (nodo *)malloc(sizeof(nodo));
  nuevo->siguiente = *lista;
  nuevo->dato = dato;
  *lista = nuevo;
}

void imprimirLista(nodo *lista)
{
  while (lista != NULL)
  {
    printf("%d -> ", lista->dato);
    lista = lista->siguiente;
  }
  printf("NULL\n");
}

// **lista es el nodo
// *lista es el puntero
void agregarFinal(nodo **lista, int dato)
{
  printf("dato lista: %d\n", (*lista)->dato);
  nodo *aux;
  aux = *lista;
  while (aux->siguiente != NULL)
  {
    printf("dato: %d\n", aux->dato);
    aux = aux->siguiente;
  }
  nodo *nuevo;
  nuevo = (nodo *)malloc(sizeof(nodo));
  nuevo->siguiente = NULL;
  nuevo->dato = dato;
  aux->siguiente = nuevo;
}

int cantidad_elementos(nodo *lista)
{
  int cantidad = 0;
  while (lista != NULL)
  {
    lista = lista->siguiente;
    cantidad++;
  }
  return cantidad;
}

void eliminarLista(nodo **lista)
{
  nodo *aux;
  while (*lista != NULL)
  {
    aux = *lista;
    *lista = (*lista)->siguiente;
    free(aux);
  }
}