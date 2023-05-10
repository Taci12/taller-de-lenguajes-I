#include <stdio.h>
#include <stdlib.h>

double *reservar_memoria(int n);
void leer_vector(double *vector, int dim);
double calcular_promedio(double *vector, int dim);
void liberar_heap(double **vector, int dim);
void imprimir_vector(double *vector, int dim);

int main()
{
  double *vector;
  int dim;
  scanf("%d", &dim);
  vector = reservar_memoria(dim);
  printf("%f", vector[0]);
  leer_vector(vector, dim);
  imprimir_vector(vector, dim);
  printf("promedio: %.2f\n", calcular_promedio(vector, dim));
  liberar_heap(&vector, dim);
  printf("%d", vector == NULL);
  return 0;
}

double *reservar_memoria(int n)
{
  double *vector;
  vector = malloc(n * sizeof(double));
  return vector;
}

void leer_vector(double *vector, int dim)
{
  int i;
  for (i = 0; i < dim; i++)
  {
    printf("valor: ");
    scanf("%lf", &vector[i]);
    printf("%f, \n", vector[i]);
  }
}

double calcular_promedio(double *vector, int dim)
{
  int promedio = 0;
  int i;
  for (i = 0; i < dim; i++)
    promedio += *vector;
  return (promedio / dim);
}

void liberar_heap(double **vector, int dim)
{
  free(*vector);
  *vector = NULL;
}

void imprimir_vector(double *vector, int dim)
{
  int i;
  printf("vector:\n");
  for (i = 0; i < dim; i++)
  {
    printf("\tposicion %d: %.2f\n", i, *vector);
    vector++;
  }
}