#include <stdio.h>
#define DIMENSION 7

void tresJuntas(float vector[], float *, float *, int *);

int main()
{
  float *ptrPromedio, promedio = 0, *ptrMinimo, minimo;
  int posMax, *ptrPosMax = &posMax;

  float vector[DIMENSION] = {4, 7.5, 3, 3.5, 1, 9.7, 10};
  ptrPromedio = &promedio;
  ptrMinimo = &minimo;
  tresJuntas(vector, ptrPromedio, ptrMinimo, ptrPosMax);

  printf("promedio: %.2f\n", *ptrPromedio);
  printf("minimo: %.2f\n", *ptrMinimo);
  printf("posicion maxima: %d\n", *ptrPosMax);
}

void tresJuntas(float vector[], float *promedio, float *minimo, int *posMax)
{
  int i, maximo = -9999;
  *minimo = 99999;
  for (i = 0; i < DIMENSION; i++)
  {
    *promedio += vector[i];

    if (vector[i] < *minimo)
    {
      *minimo = vector[i];
    }

    if (vector[i] > maximo)
    {
      maximo = vector[i];
      *posMax = i;
    }
  }
  *promedio /= DIMENSION;
}