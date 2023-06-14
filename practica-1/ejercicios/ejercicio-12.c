#include <stdio.h>
#include <math.h>

int main()
{
  int i;
  for (i = 1; i <= 10; i++)
  {
    printf("La raiz cuadrada de %d es: %.2f\n", i, sqrt(i));
    printf("%d al cuadrado es: %.2f\n", i, pow(i, 2));
    printf("%d al cubo es: %.2f\n", i, pow(i, 3));
    printf("\n");

    return 0;
  }
}