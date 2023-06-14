#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 1000
#define DEBUG 1

int *generar_vector(int dim);
int buscar_posicion(int *vector, int elemento, int dim);

int main()
{
  int *vector = generar_vector(DIM);
  int posicion = buscar_posicion(vector, vector[4], DIM);
  printf("La posicion de %d es %d\n", vector[4], posicion);
  return 0;
}

int *generar_vector(int dim)
{
  int *vector = malloc(dim * sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < dim; i++)
    vector[i] = rand() % 1000;
  return vector;
}

int buscar_posicion(int *vector, int elemento, int dim)
{
  int i;
  for (i = 0; i < dim; i++)
    if (vector[i] == elemento)
      return i;

#ifdef DEBUG
  printf("Se accedio %d veces\n", i);
#endif
  return -1;
}