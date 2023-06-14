#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "extra.h"

void imprimirVectorEnteros(int *vector, int dim);
void crearArreglo(int **vector, int dim);
void iniciarEnRandom(int *vector, int dim);
int retornarMaximo(int *vector, int dim);

int main()
{
  int *n = (int *)malloc(sizeof(int));
  printf("Introduzca un unsigned:\n");
  scanf("%d", n);
  printf("n = %d\n", *n);
  int *vector;
  crearArreglo(&vector, *n);
  iniciarEnRandom(vector, *n);
  imprimirVectorEnteros(vector, *n);
  int maximo = retornarMaximo(vector, *n);
  printf("El numero maximo es %d", maximo);
}

void crearArreglo(int **vector, int dim)
{
  *vector = (int *)malloc(dim * sizeof(int));
}

void iniciarEnRandom(int *vector, int dim)
{
  srand(time(NULL));
  int i;
  for (i = 0; i < dim; i++)
    vector[i] = rand() % 99;
}

int retornarMaximo(int *vector, int dim)
{
  int i, maximo = vector[0];
  for (i = 1; i < dim; i++)
  {
    if (vector[i] > maximo)
      maximo = vector[i];
  }
  return maximo;
}