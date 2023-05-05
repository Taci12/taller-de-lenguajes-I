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
  return 0;
  imprimirLista(lista);
  nodo *listaInvertida;
  listaInvertida = invertirLista(lista);
  imprimirLista(lista);
  imprimirLista(listaInvertida);
}

nodo *invertirLista(nodo *lista)
{
  nodo *listaInvertida;
  listaInvertida = (nodo *)malloc(sizeof(nodo));
  iniciarLista(&listaInvertida);
  while (lista != NULL)
  {
    agregarInicio(&listaInvertida, lista->dato);
    lista = lista->siguiente;
  }
  return listaInvertida;
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