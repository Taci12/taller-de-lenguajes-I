#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *archivo;
  archivo = fopen("../textos/apuestas.txt", "r");
  int monto = 0, codigo;
  fscanf(archivo, "%d|%d;", &codigo, &monto);
  int monto_total = 0;
  while (!feof(archivo))
  {
    monto_total += monto;
    fscanf(archivo, "%d|%d;", &codigo, &monto);
  }
  printf("monto total: %d", monto_total);
  return 0;
}