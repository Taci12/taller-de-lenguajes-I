#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **reservar_memoria(int n);
void inicializar_matriz(int **matriz, int n);
void imprimir_matriz(int **matriz, int n);
void liberar_memoria(int ***matriz, int n);

int main()
{
  int n;
  printf("Ingrese un valor: \n");
  scanf("%d", &n);
  int **matriz;
  matriz = reservar_memoria(n);
  inicializar_matriz(matriz, n);
  imprimir_matriz(matriz, n);
  liberar_memoria(&matriz, n);
  printf("%d", matriz == NULL);
}

int **reservar_memoria(int n)
{
  int **matriz;
  int i;
  matriz = malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
    matriz[i] = malloc((i + 1) * sizeof(int));
  return matriz;
}

void inicializar_matriz(int **matriz, int n)
{
  srand(time(NULL));
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < i + 1; j++)
      matriz[i][j] = rand() % 21;
}

void imprimir_matriz(int **matriz, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (j < i + 1)
        printf("%d ", matriz[i][j]);
      else
        printf("0 ");
    }
    printf("\n");
  }
}

void liberar_memoria(int ***matriz, int n)
{
  int i;
  for (i = 0; i < n; i++)
    free(matriz[0][i]);
  free(*matriz);
  *matriz = NULL;
}