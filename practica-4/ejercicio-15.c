#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **iniciar_matriz(int dim);
void imprimir_matriz(int **matriz, int dim);

int main()
{
  int **matriz;
  int dim;
  printf("Dimension: \n");
  scanf("%d", &dim);
  matriz = iniciar_matriz(dim);
  imprimir_matriz(matriz, dim);
  return 0;
}

int **iniciar_matriz(int dim)
{
  srand(time(NULL));
  int **matriz;
  matriz = malloc(dim * sizeof(int *));
  int i, j;
  for (i = 0; i < dim; i++)
  {
    matriz[i] = malloc(i * sizeof(int));
    for (j = 0; i >= j; j++)
      if (j == 0 || j == i)
        matriz[i][j] = 1;
      else
        matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - 1];
  }
  return matriz;
}

void imprimir_matriz(int **matriz, int dim)
{
  int i, j;
  for (i = 0; i < dim; i++)
  {
    for (j = 0; j <= i; j++)
      printf("%d ", matriz[i][j]);
    printf("\n");
  }
}