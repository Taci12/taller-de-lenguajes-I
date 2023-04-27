#include <stdio.h>

int invertir_entero(int numero)
{
  int invertido = 0;
  while (numero != 0)
  {
    invertido = invertido * 10 + numero % 10;
    numero /= 10;
  }
  return invertido;
}

int main()
{
  int numero;
  printf("Ingrese el entero a invertir:\n");
  scanf("%d", &numero);
  printf("El numero invertido es %d", invertir_entero(numero));
}