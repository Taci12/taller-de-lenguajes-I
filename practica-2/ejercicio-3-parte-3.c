#include <stdio.h>
#define DIM 17

void reemplazarCaracter(char string[], char char1, char char2);

int main()
{
  char cadena[DIM] = "goooolazo";
  char char1 = 'o';
  char char2 = 'i';
  printf("%s\n", cadena);
  reemplazarCaracter(cadena, char1, char2);
  printf("%s\n", cadena);
}

void reemplazarCaracter(char *string, char char1, char char2)
{
  while (*string != '\0')
  {
    if (*string == char1)
    {
      *string = char2;
    }
    string++;
  }
}