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
int leerInt();
nodo *invertirLista(nodo *);

int main()
{
  int numero;
  numero = leerInt();
  nodo *lista;
  iniciarLista(&lista);
  while (numero != 0)
  {
    agregarFinal(&lista, numero);
    numero = leerInt();
  }
  imprimirLista(lista);
  numero = leerInt();
  eliminarMultiplos(&lista, numero);
  imprimirLista(lista);
  return 0;
}

void eliminarMultiplos(nodo **lista, int numero)
{
  nodo *actual;
  actual = *lista;
  nodo *anterior;
  anterior = actual;
  nodo *aux;
  while (actual != NULL)
  {
    if ((actual->dato % numero) == 0)
    {
      if (actual == anterior)
      {
        *lista = actual->siguiente; // avanzo una posicion
        free(actual);
        actual = *lista;
        anterior = actual;
      }
      else
      {
        aux = actual;
        actual = actual->siguiente;
        anterior->siguiente = actual;
        free(aux);
      }
    }
    else
    {
      anterior = actual;
      actual = actual->siguiente;
    }
  }
}

int leerInt()
{
  int numero;
  printf("Numero: ");
  scanf("%d", &numero);
  printf("\n");
  return numero;
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
  if (*lista == NULL)
    agregarInicio(lista, dato);
  else
  {
    nodo *aux;
    aux = *lista;
    while (aux->siguiente != NULL)
      aux = aux->siguiente;
    agregarInicio(aux, dato);
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