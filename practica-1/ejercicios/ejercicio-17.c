#include <stdio.h>

int maximo_minimo(int cantidad);

int main()
{
  int cantidad;
  printf("Introduzca la cantidad de veces:\n");
  scanf("%d", cantidad)
      maximo_minimo(cantidad);
}

void maximo_minimo(int cantidad)
{
  float max = -1, min = 9999999, entrada;
  int i;
  for (i = 0; i < cantidad; i++)
  {
    printf("Ingrese un flotante:\n");
    scanf("%f", &entrada);
    if (entrada < min)
      min = entrada;
    else if (entrada > max)
      max = entrada;
  }
  printf("El maximo valor ingresado fue %.2f y el minimo %.2f.", max, min);
}
