#include <stdio.h>

int main()
{
  float km, resultado;
  printf("Introduzca distancia en kilometros:\n");
  scanf("%f", &km);
  resultado = km / 1.61;
  printf("%.2f kilometros equivalen a %.2f millas\n", km, resultado);
  return 0;
}
