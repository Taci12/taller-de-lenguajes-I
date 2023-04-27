#include <stdio.h>
#include <string.h>

void cantidad_letras_contenidas(char *, int *);
void iniciar_en_cero(int *, int dim);
void imprimirCantidades(int *cantidades, int dim);

int main()
{
  printf("%d", (int)'a');
  int cantidad_letras[25];
  iniciar_en_cero(cantidad_letras, 25);
  char string[30] = "aaabbc";
  cantidad_letras_contenidas(string, cantidad_letras);
  imprimirCantidades(cantidad_letras, 25);
  return 0;
}

void cantidad_letras_contenidas(char *palabra, int *cantidad_letras)
{
  // el valor hex de 'a' es 97 y el de 'z' 122
  // le resto 97 al caracter y almaceno en un vector
  int resultado = 0;
  while (*palabra != '\0')
  {
    cantidad_letras[*palabra - 97]++;
    palabra++;
  }
}

void iniciar_en_cero(int *vector, int dim)
{
  int i;
  for (i = 0; i < dim; i++)
  {
    *vector = 0;
    vector++;
  }
}

void imprimirCantidades(int *cantidades, int dim)
{
  int i;
  for (i = 0; i < dim; i++, cantidades++)
  {
    printf("cantidad de %c: %d\n", i + 97, *cantidades);
  }
}