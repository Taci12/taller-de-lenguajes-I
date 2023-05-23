#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 200

typedef struct
{
  float promedio;
  float maximo;
  float minimo;
} caracteristicas;

caracteristicas *obtener_valores(FILE *);
void imprimir_valores(caracteristicas *, FILE *);
void leer_fila(float *, FILE *);
void procesar_fila(float *, caracteristicas *, int *filas);
void iniciar_vector(caracteristicas *vector);
void obtener_promedios(caracteristicas *vector, int *filas);

int main()
{
  FILE *vinos;
  vinos = fopen("../textos/vinos.csv", "r");
  if (!vinos)
  {
    printf("error al abrir vinos.csv");
    return -1;
  }
  FILE *resultados;
  resultados = fopen("../textos/resultados.csv", "w");
  if (!resultados)
  {
    printf("error al crear resultados.csv");
    return -1;
  }
  char linea[DIM];
  // creo el encabezado
  fprintf(resultados, "Atributos;");
  fgets(linea, DIM, vinos);
  fputs(linea, resultados);

  caracteristicas *vector;
  vector = obtener_valores(vinos);
  fclose(vinos);
  imprimir_valores(vector, resultados);
  fclose(resultados);
  return 0;
}

// obtiene los valores a imprimir en el archivo
caracteristicas *obtener_valores(FILE *vinos)
{
  caracteristicas *vector = calloc(8, sizeof(caracteristicas));
  iniciar_vector(vector);
  float *fila_actual = calloc(8, sizeof(float));
  float *linea = malloc(DIM * sizeof(float));
  int *filas;
  filas = calloc(1, sizeof(int));

  leer_fila(fila_actual, vinos);
  while (!feof(vinos))
  {
    procesar_fila(fila_actual, vector, filas);
    leer_fila(fila_actual, vinos);
    *filas += 1;
  }
  obtener_promedios(vector, filas);
  free(filas);
  free(fila_actual);
  free(linea);
  return vector;
}

void iniciar_vector(caracteristicas *vector)
{
  int i;
  for (i = 0; i < 8; i++, vector++)
  {
    vector->maximo = -1;
    vector->minimo = 9999;
    vector->promedio = 0;
  }
}

// lee la fila actual y la almacena al vector fila_actual
void leer_fila(float *fila_actual, FILE *vinos)
{
  int i;
  char categoria[10];
  for (i = 0; i < 8; i++, fila_actual++)
    fscanf(vinos, "%f;", fila_actual);
  fscanf(vinos, "%s;", categoria); // leo la caracteristica "tipo"
}

// agrega al vector de caracteristicas la fila actual
void procesar_fila(float *fila_actual, caracteristicas *vector, int *filas)
{
  int i;
  for (i = 0; i < 8; i++, fila_actual++, vector++)
  {
    printf("Fila actual: %.2f\n", *fila_actual);
    vector->promedio += (*fila_actual);
    if (*fila_actual < vector->minimo)
      vector->minimo = (*fila_actual);
    if (*fila_actual > vector->maximo)
      vector->maximo = (*fila_actual);
  }
  *filas += 1;
}

void obtener_promedios(caracteristicas *vector, int *filas)
{
  int i;
  for (i = 0; i < 8; i++, vector++)
    vector->promedio /= (*filas);
}

void imprimir_valores(caracteristicas *vector, FILE *resultados)
{
  int i;
  fprintf(resultados, "Promedio;");
  for (i = 0; i < 8; i++)
    fprintf(resultados, "%.2f;", vector[i].promedio);
  fprintf(resultados, "\nMaximo;");
  for (i = 0; i < 8; i++)
    fprintf(resultados, "%.2f;", vector[i].maximo);
  fprintf(resultados, "\nMinimo;");
  for (i = 0; i < 8; i++)
    fprintf(resultados, "%.2f;", vector[i].minimo);
  fprintf(resultados, "\n");
}