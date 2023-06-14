#include <stdio.h>
#include <stdlib.h>

float **reservar_memoria(int filas, int columnas);

int main()
{
  int filas, columnas;
  printf("filas: ");
  scanf("%d", &filas);
  printf("columnas: ");
  scanf("%d", &columnas);
  float **matriz;
  matriz = generar_matriz(filas, columnas);

  return 0;
}

float **reservar_memoria(int filas, int columnas)
{
  float **matriz;
  matriz = malloc(filas * sizeof(double *));
  int i;
  for (i = 0; i < filas; i++, matriz++)
    *matriz = malloc(columnas * sizeof(float));
  return matriz;
}

void imprimir_matriz(float **matriz, int filas, int columnas)
{
}
