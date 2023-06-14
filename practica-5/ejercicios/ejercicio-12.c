#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int dni;
  int desplazamiento;
} bloque;

struct l
{
  struct l *siguiente;
  bloque dato;
};

typedef struct l nodo;

void iniciar_lista(nodo **);
void agregar_inicio(nodo **, bloque dato);
void imprimir_lista(nodo *);
void agregar_final(nodo **, bloque dato);
int cantidad_elementos(nodo *lista);
void insertar_ordenado(nodo **lista, bloque dato);
void generar_lista_indice(nodo **lista, FILE *personas);
int obtener_dni(char *fila);
FILE *generar_archivo_indice(nodo *lista);

int main()
{
  FILE *personas;
  personas = fopen("../textos/personas.csv", "r");
  nodo *lista;
  iniciar_lista(&lista);
  generar_lista_indice(&lista, personas);
  imprimir_lista(lista);
  FILE *indice;
  indice = generar_archivo_indice(lista);
  return 0;
}

// genera una lista con structs bloque, que cada uno tiene el desplazamiento
// y el dni de cierta persona.
void generar_lista_indice(nodo **lista, FILE *personas)
{
  bloque actual;
  actual.dni = 0;
  actual.desplazamiento = 0;
  char *fila;
  fila = (char *)malloc(300 * sizeof(char));

  fgets(fila, 300, personas);
  actual.desplazamiento = strlen(fila);
  int id;
  while (!feof(personas))
  {
    // agrego el desplazamiento anterior mas el de la ultima linea
    fgets(fila, 300, personas);
    sscanf(fila, "%d;%d", &id, &actual.dni);
    insertar_ordenado(lista, actual);
    actual.desplazamiento += strlen(fila);
    fgets(fila, 300, personas);
  }
}

FILE *generar_archivo_indice(nodo *lista)
{
  FILE *indice;
  indice = fopen("../textos/personas.idx", "wb");
  int *datos;
  datos = (int *)malloc(2 * sizeof(int));
  while (lista->siguiente != NULL)
  {
    datos[0] = lista->dato.dni;
    datos[1] = lista->dato.desplazamiento;
    fwrite(datos, sizeof(int), 2, indice);
    lista = lista->siguiente;
  }
  return indice;
}

void iniciar_lista(nodo **lista)
{
  *lista = NULL;
}

void agregar_inicio(nodo **lista, bloque dato)
{
  nodo *nuevo;
  nuevo = (nodo *)malloc(sizeof(nodo));
  nuevo->siguiente = *lista;
  nuevo->dato = dato;
  *lista = nuevo;
}

void imprimir_lista(nodo *lista)
{
  while (lista != NULL)
  {
    printf("{ dni: %d, esplazamiento %d }", lista->dato.dni, lista->dato.desplazamiento);
    lista = lista->siguiente;
  }
  printf("NULL\n");
}

void agregar_final(nodo **lista, bloque dato)
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

void insertar_ordenado(nodo **lista, bloque dato)
{
  if (*lista == NULL)
    agregar_inicio(lista, dato);
  else
  {
    nodo *anterior;
    nodo *actual;
    actual = *lista;
    anterior = actual;
    while ((actual->siguiente != NULL) && (actual->dato.dni <= dato.dni))
    {
      anterior = actual;
      actual = actual->siguiente;
    }
    nodo *nuevo;
    nuevo = malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = actual;
    anterior->siguiente = nuevo;
  }
}