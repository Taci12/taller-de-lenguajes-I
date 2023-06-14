#include <stdio.h>
#include <stdlib.h>
#define CANT 5

void leer_vector(int *vector, int dim);
void escribir_archivos(FILE *archivoBinario, FILE *archivoTexto, int *vector, int dim);

int main()
{
  int *vector;
  vector = malloc(CANT * sizeof(int));
  leer_vector(vector, CANT);
  FILE *archivoBinario;
  archivoBinario = fopen("../textos/numeros.dat", "wb");
  FILE *archivoTexto;
  archivoTexto = fopen("../textos/numeros.txt", "w");
  escribir_archivos(archivoBinario, archivoTexto, vector, CANT);
  return 0;
}

void leer_vector(int *vector, int dim)
{
  int i;
  for (i = 1; i <= dim; i++, vector++)
  {
    printf("Numero %d:", i);
    scanf("%d", vector);
  }
}

void escribir_archivos(FILE *archivoBinario, FILE *archivoTexto, int *vector, int dim)
{
  int i;
  for (i = 0; i < dim; i++)
    fprintf(archivoTexto, "%d ", vector[i]);
  fwrite(vector, sizeof(int), dim, archivoBinario);
}