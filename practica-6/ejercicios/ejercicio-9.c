#include "./imath.h"

int main()
{
  int numero;
  printf("Introduzca un numero: \n");
  scanf("%d", &numero);
  printf("cuadrado: %d\n", cuadrado(numero));
  printf("cubo: %d\n", cubo(numero));
  printf("absoluto: %d\n", absoluto(numero));
  printf("par: %d\n", par(numero));
  printf("factorial: %d\n", factorial(numero));
}