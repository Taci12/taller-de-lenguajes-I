#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
  FILE *habitantes;
  habitantes = fopen("./Habitantes.txt", "r");
  FILE *resultado;
  resultado = fopen("./Habitantes.dat", "wb+");
  destino linea;
  if (habitantes == NULL)
  {
    printf("Error al abrir habitantes");
    return -1;
  }
  if (resultado == NULL)
  {
    printf("Error al abrir el archivo resultado");
    return -1;
  }
  // leo los datos y los pego en el archivo resultado
  fscanf(habitantes, "%d %d %s %d\n", &linea.codProv, &linea.codLoc, linea.nomLoc, &linea.nHab);
  while (!feof(habitantes))
  {
    fwrite(&linea, sizeof(destino), 1, resultado);
    fscanf(habitantes, "%d %d %s %d\n", &linea.codProv, &linea.codLoc, linea.nomLoc, &linea.nHab);
  }

  fseek(resultado, 0, SEEK_SET);
  char *maxNom = malloc(30 * sizeof(char));
  int maxCod = 0;
  int maxHab = -1;
  fread(&linea, sizeof(destino), 1, resultado);
  while (!feof(resultado))
  {
    if (linea.nHab > maxHab)
    {
      strcpy(maxNom, linea.nomLoc);
      maxCod = linea.codLoc;
      maxHab = linea.nHab;
    }
    fread(&linea, sizeof(destino), 1, resultado);
  }
  fclose(resultado);
  fclose(habitantes);
  printf("Nombre: %s, codigo: %d", maxNom, maxCod);
  return 0;
}