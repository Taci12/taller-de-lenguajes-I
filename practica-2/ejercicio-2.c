#include <stdio.h>
#include <stdlib.h>
#define DIML 5

float promedio(float vector[], int dimL);
float minimo(float vector[], int dimL);
int posicionMaxima(float vector[], int dimL);

int main()
{
  float vector[DIML] = {3, 5, 77.2, 99.1, 100};
  printf("promedio: %.2f\n", promedio(vector, DIML));
  printf("minimo: %.2f\n", minimo(vector, DIML));
  printf("posicion maxima: %d\n", posicionMaxima(vector, DIML));
}

float promedio(float vector[], int dimL)
{
  int i;
  float resultado = 0;

  for (i = 0; i < dimL; i++)
  {
    resultado += vector[i];
  }

  if (dimL != 0)
    return ((float)resultado / dimL);
  else
    return 0;
}

float minimo(float vector[], int dimL)
{
  float minimo = 99999999999;
  int i;
  for (i = 0; i < dimL; i++)
  {
    if (vector[i] < minimo)
      minimo = vector[i];
  }

  return minimo;
}

int posicionMaxima(float vector[], int dimL)
{
  float maximo = -9999999;
  int i, posicionMaxima;

  for (i = 0; i < dimL; i++)
  {
    if (vector[i] > maximo)
    {
      maximo = vector[i];
      posicionMaxima = i;
    }
  }

  return posicionMaxima;
}
