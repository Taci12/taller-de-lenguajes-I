#include <stdio.h>

#define FILAS 6
#define COLUMNAS 6

void transponerMatriz(int matriz[][COLUMNAS]);
void imprimirMatriz(int matriz[][COLUMNAS]);
void generarMatriz(int matriz[][COLUMNAS]);

int main()
{
  int matriz[FILAS][COLUMNAS];
  generarMatriz(matriz);
  printf("Matriz antes de transponer: \n");
  imprimirMatriz(matriz);

  printf("Matriz transpuesta:\n");
  transponerMatriz(matriz);
  imprimirMatriz(matriz);

  return 0;
}

void transponerMatriz(int matriz[][COLUMNAS])
{
  int i, j, temp;
  for (i = 0; i < FILAS; i++)
  {
    for (j = 0; j < COLUMNAS; j++)
    {
      if (i <= j)
      {
        temp = matriz[i][j];
        matriz[i][j] = matriz[j][i];
        matriz[j][i] = temp;
      }
    }
  }
}

void imprimirMatriz(int matriz[][COLUMNAS])
{
  int i, j;
  for (i = 0; i < FILAS; i++)
  {
    for (j = 0; j < COLUMNAS; j++)
    {
      printf(" %d ", matriz[i][j]);
    }
    printf("\n");
  }
}

void generarMatriz(int matriz[][COLUMNAS])
{
  int i, j;

  for (i = 0; i < FILAS; i++)
  {
    for (j = 0; j < COLUMNAS; j++)
    {
      matriz[i][j] = rand() % 100;
    }
  }
}