#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30

struct l
{
  struct l *siguiente;
  char dato[DIM];
};

typedef struct l nodo;

void iniciar_lista(nodo **);
void agregar_inicio(nodo **, char *dato);
void imprimir_lista(nodo *);
void agregar_final(nodo **, char *dato);
int cantidad_elementos(nodo *lista);
void generar_lista(FILE *archivo, nodo **lista);
void leer_palabra(char **palabra);
int pertenece(nodo *lista, char *palabra);

int main()
{
  FILE *archivo;
  archivo = fopen("../textos/diccionario.txt", "r");
  nodo *lista;
  iniciar_lista(&lista);
  generar_lista(archivo, &lista);
  char *palabra;
  palabra = malloc(DIM * sizeof(char));
  imprimir_lista(lista);
  leer_palabra(&palabra);
  // mientras palabra sea distinto a ZZZ
  while (!strcmp(palabra, "ZZZ"))
  {
    if (pertenece(lista, palabra))
      printf("La palabra pertenece al diccionario\n");
    else
      printf("La palabra no pertenece al diccionario\n");
    leer_palabra(&palabra);
  }
}

void leer_palabra(char **palabra)
{
  printf("Introduzca palabra: ");
  scanf("%s", *palabra);
}

// retorna 1 si pertenece a la lista, sino retorna 0
int pertenece(nodo *lista, char *palabra)
{
  // mientras la lista no termine y palabra sea mayor al dato actual
  while ((lista->siguiente != NULL) && (strcmp(palabra, lista->dato) > 0))
  {
    if (!strcmp(lista->dato, palabra))
      return 1;
    else
      lista = lista->siguiente;
  }
  return 0;
}

void generar_lista(FILE *archivo, nodo **lista)
{
  char *linea;
  linea = malloc(DIM * sizeof(char));
  fgets(linea, DIM, archivo);
  while (!feof(archivo))
  {
    agregar_final(lista, linea);
    fgets(linea, DIM, archivo);
  }
}

void iniciar_lista(nodo **lista)
{
  *lista = NULL;
}

void agregar_inicio(nodo **lista, char *dato)
{
  nodo *nuevo;
  nuevo = (nodo *)malloc(sizeof(nodo));
  nuevo->siguiente = *lista;
  strcpy(nuevo->dato, dato);
  *lista = nuevo;
}

void imprimir_lista(nodo *lista)
{
  while (lista != NULL)
  {
    puts(lista->dato);
    lista = lista->siguiente;
  }
  printf("NULL\n");
}

// **lista es el nodo
// *lista es el puntero
void agregar_final(nodo **lista, char *dato)
{
  if (*lista == NULL)
    agregar_inicio(lista, dato);
  else
  {
    nodo *aux;
    aux = *lista;
    while (aux->siguiente != NULL)
      aux = aux->siguiente;
    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->siguiente = NULL;
    strcpy(nuevo->dato, dato);
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

void eliminar_lista(nodo **lista)
{
  nodo *aux;
  while (*lista != NULL)
  {
    aux = *lista;
    *lista = (*lista)->siguiente;
    free(aux);
  }
}