#include <stdio.h>
/*Retorno un factorial de forma iterativa y recursiva*/
int factorial_iterativo(int numero)
{
  int i, resultado = 1;
  for (i = numero; i > 0; i--)
  {
    resultado *= i;
  }
  return resultado;
}

int factorial_recursivo(int numero)
{
  if (numero > 1)
    return (numero * factorial_recursivo(numero - 1));
}

int main()
{
  int numero;
  printf("Introduzca un entero para hacer factorial:\n");
  scanf("%d", &numero);
  printf("factorial iterativo: %d\n", factorial_iterativo(numero));
  printf("factorial recursivo: %d\n", factorial_recursivo(numero));
}