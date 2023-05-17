#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *archivo;
  archivo = fopen("prueba.txt", "r");
  int actual;
  if (archivo == NULL)
  {
    printf("error al abrir el archivo");
    return 0;
  }
  fscanf(archivo, "%d-", &actual);
  // printf("actual: %d\n", actual);
  int maximo = actual;
  int dia = 1;
  int maxDia = 1;
  while (!feof(archivo))
  {
    if (actual > maximo)
    {
      maximo = actual;
      maxDia = dia;
    }
    printf("actual: %d\n", actual);
    fscanf(archivo, "%d-", &actual);
    dia++;
  }
  fclose(archivo);
  printf("maximo: %d\n", maximo);
  printf("maximo dia: %d", maxDia);
  return 0;
}