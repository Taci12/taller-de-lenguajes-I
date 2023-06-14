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
  FILE *binario = fopen("Habitantes.dat", "wb+");

  if (archivo == NULL)
  {
    printf("Error al abrir el archivo de texto");
    return -1;
  }
  if (binario == NULL)
  {
    printf("Error al abrir el archivo binario");
    return -1;
  }

  fscanf(archivo, "%d %d %s %d", &linea.codProv, &linea.codLoc, linea.nomLoc, &linea.nHab);
  while (!feof(archivo))
  {
    cantidad_lineas++;
    fwrite(&linea, sizeof(destino), 1, binario);
    fscanf(archivo, "%d %d %s %d", &linea.codProv, &linea.codLoc, linea.nomLoc, &linea.nHab);
  }
  destino *vector = malloc(cantidad_lineas * sizeof(destino));
  fseek(binario, 0, SEEK_SET);
  fread(vector, sizeof(destino), cantidad_lineas, binario);
  int i;
  destino max = {0, 0, ' ', -1};
  for (i = 0; i < cantidad_lineas; i++)
  {
    if (vector[i].nHab > max.nHab)
      max = vector[i];
  }
  printf("El maximo es %s con codigo %d\n", max.nomLoc, max.codLoc);
  fclose(archivo);
  fclose(binario);
  return 0;
}