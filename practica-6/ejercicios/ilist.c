#include <stdlib.h>
#include <stdio.h>
#include "./ilist.h"

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
  if (*lista == NULL)
    agregarInicio(lista, dato);
  else
  {
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