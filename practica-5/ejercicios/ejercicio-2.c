#include <stdio.h>
#include <stdlib.h>
#define LONG 300

typedef struct
{
  int mayusculas;
  int minusculas;
  int digitos;
} cantidades;

void procesar_linea(char *, cantidades *);

int main()
{
  cantidades cants = {0, 0, 0};
  FILE *archivo;
  char linea[LONG];
  archivo = fopen("prueba.txt", "r");
  puts("Archivo:");
  fgets(linea, LONG, archivo);
  while (!feof(archivo))
  {
    procesar_linea(linea, &cants);
    puts(linea);
    fgets(linea, LONG, archivo);
  }
  printf("minusculas: %d, mayusculas: %d, digitos: %d", cants.minusculas, cants.mayusculas, cants.digitos);
  fclose(archivo);
}

void procesar_linea(char *linea, cantidades *cants)
{
  while (*linea != '\0')
  {
    char actual = *linea;
    if (actual >= 97 && actual <= 122)
      cants->minusculas++;
    else if (actual >= 65 && actual <= 90)
      cants->mayusculas++;
    else if (actual >= 48 && actual <= 57)
      cants->digitos++;
    linea++;
  }
}