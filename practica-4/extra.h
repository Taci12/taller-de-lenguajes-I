// es solo hasta que nos den el tema
#include <stdio.h>

void imprimirVectorEnteros(int *vector, int dim)
{
  int i;
  printf("vector:");
  for (i = 0; i < dim; i++)
    printf("\tvector[%d] = %d\n", i, vector[i]);
}