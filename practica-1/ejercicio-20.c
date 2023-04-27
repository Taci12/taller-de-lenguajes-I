#include <stdio.h>

int damePar();

int main()
{
  int n, i;
  printf("Introduzca n:\n");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("El numero %d es %d\n", i, damePar());
  }
}

int damePar()
{
  static int numero = -2;
  numero += 2;
  return numero;
}