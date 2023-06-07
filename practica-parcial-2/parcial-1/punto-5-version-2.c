#include <stdio.h>
#include <stdlib.h>

struct destino
{
  int codProv;
  int codLoc;
  char nomLoc[30];
  int nHab;
};

typedef struct destino destino;

int main()
{
  FILE *archivo;
  archivo = fopen("Habitantes.txt", "r");
  int cantidad_lineas = 0;
  destino linea;
  FILE *binario = fopen("Habitantes.dat", "wb");

  fscanf(archivo, "%d %d %s %d", &linea.codProv, &linea.codLoc, linea.nomLoc, &linea.nHab);
  while (!feof(archivo))
  {
    cantidad_lineas++;
    fwrite(&linea, sizeof(destino), 1, binario);
    fscanf(archivo, "%d %d %s %d", &linea.codProv, &linea.codLoc, linea.nomLoc, &linea.nHab);
  }
  int *vector = malloc(cantidad_lineas * sizeof(destino));
}