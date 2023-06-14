#include <stdio.h>
#define DIMENSION 3

void imprimirMatriz(int matriz[][DIMENSION]);
void generarMatriz(int matriz[][DIMENSION]);
void sumarMatriz(int matriz1[][DIMENSION], int matriz2[][DIMENSION], int matriz3[][DIMENSION]);

int main()
{
  int matriz1[DIMENSION][DIMENSION];
  int matriz2[DIMENSION][DIMENSION];
  int matriz3[DIMENSION][DIMENSION];
  generarMatriz(matriz1);
  generarMatriz(matriz2);
  generarMatriz(matriz3);

  printf("Matriz 1\n");
  imprimirMatriz(matriz1);

  printf("Matriz 2\n");
  imprimirMatriz(matriz2);

  printf("Matriz 3\n");
  imprimirMatriz(matriz3);

  printf("suma:\n");

  sumarMatriz(matriz1, matriz2, matriz3);

  printf("Matriz 1\n");
  imprimirMatriz(matriz1);
}

void sumarMatriz(int matriz1[][DIMENSION], int matriz2[][DIMENSION], int matriz3[][DIMENSION])
{
  int i, j;
  for (i = 0; i < DIMENSION; i++)
  {
    for (j = 0; j < DIMENSION; j++)
    {
      matriz1[i][j] = matriz1[i][j] + matriz2[i][j] + matriz3[i][j];
    }
  }
}

void imprimirMatriz(int matriz[][DIMENSION])
{
  int i, j;
  for (i = 0; i < DIMENSION; i++)
  {
    for (j = 0; j < DIMENSION; j++)
    {
      printf(" %d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void generarMatriz(int matriz[][DIMENSION])
{
  int i, j;

  for (i = 0; i < DIMENSION; i++)
  {
    for (j = 0; j < DIMENSION; j++)
    {
      matriz[i][j] = rand() % 100;
    }
  }
}