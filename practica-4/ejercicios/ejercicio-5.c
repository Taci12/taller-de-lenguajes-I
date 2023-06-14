#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int minusculas;
  int mayusculas;
} s_letras;

s_letras contarLetras(char *string);
// a = 97
// z = 122
// A = 65
// Z = 90
int main()
{
  char *string = (char *)calloc(100, sizeof(char));
  int i;
  for (i = 0; i < 10; i++)
  {
    printf("Introduzca string: \n");
    gets(string);
    s_letras letras = contarLetras(string);
    printf("\tMinusculas: %d\n", letras.minusculas);
    printf("\tMayusculas: %d\n", letras.mayusculas);
  }
  free(string);
  return 0;
}

s_letras contarLetras(char *string)
{
  s_letras cantidad = {0, 0};
  while (*string != '\0')
  {
    if ((*string >= 65) && (*string <= 90))
      cantidad.mayusculas++;
    else if ((*string >= 97) && (*string <= 122))
      cantidad.minusculas++;
    string++;
  }
  return cantidad;
}