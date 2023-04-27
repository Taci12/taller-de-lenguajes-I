#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIML 50

int main()
{
  int vec[DIML];
  int i;
  srand(time(NULL));
  int iImparNumeroPar = 0, iParNumeroImpar = 0;

  for (i = 0; i < DIML; i++)
  {
    vec[i] = rand();
    if ((i % 2) && (vec[i] % 2 == 0))
    {
      iImparNumeroPar += 1;
    }
    else if ((i % 2 == 1) && (vec[i] % 2 != 0))
    {
      iParNumeroImpar += 1;
    }
  }

  printf("La cantidad de numeros pares en posiciones impares es %d\n", iImparNumeroPar);
  printf("La cantidad de numeros impares en posiciones pares es %d\n", iParNumeroImpar);
}