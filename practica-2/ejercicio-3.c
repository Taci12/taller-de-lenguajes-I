#include <stdio.h>
#include <stdlib.h>

#define COLUMNAS 5

#define FILAS 2

void multiplicarMatriz(int matriz[][COLUMNAS], int columnas, int filas, int constante);
void imprimirMatriz(int matriz[][COLUMNAS], int columnas, int filas);

int main()
{
  int matriz[FILAS][COLUMNAS];

  int i, j;

  for (i = 0; i < FILAS; i++)
  {
    for (j = 0; j < COLUMNAS; j++)
    {
      matriz[i][j] = rand() % 100;
    }
  }

  imprimirMatriz(matriz, COLUMNAS, FILAS);

  multiplicarMatriz(matriz, COLUMNAS, FILAS, 2);
  printf("\n");

  imprimirMatriz(matriz, COLUMNAS, FILAS);

  return 0;
}

void multiplicarMatriz(int matriz[][COLUMNAS], int columnas, int filas, int constante)
{
  int i, j;
  for (i = 0; i < filas; i++)
  {
    for (j = 0; j < columnas; j++)
    {
      matriz[i][j] *= constante;
    }
  }
}

void imprimirMatriz(int matriz[][COLUMNAS], int columnas, int filas)
{
  int i, j;
  for (i = 0; i < filas; i++)
  {
    for (j = 0; j < columnas; j++)
    {
      printf(" %d ", matriz[i][j]);
    }
    printf("\n");
  }
}
