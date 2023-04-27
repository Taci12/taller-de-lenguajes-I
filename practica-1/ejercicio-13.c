#include <stdio.h>

int es_primo(int numero)
{
  int i;
  for (i = 1; i < numero; i++)
  {
    if ((numero % i == 0) && (i != 1))
      return 0;
  }
  return 1;
}

int main()
{
  int i = 0, numero;
  while (i < 5)
  {
    printf("Ingrese un entero:\n");
    scanf("%d", &numero);
    if (es_primo(numero))
      i++;
    printf("La cantidad de enteros ingresados es de %d\n", i);
  }
}