#include <stdio.h>
#include <string.h>
#define LENG 15

char ultimoCaracter(char string[]);

int main()
{
  char string[LENG];
  int cant = 0;
  printf("Introduzca una string:\n");
  scanf("%s", string);
  while (strcmp(string, "XXX"))
  {
    if (ultimoCaracter(string) == 'o')
      cant++;
    printf("Introduzca una string:\n");
    scanf("%s", string);
  }
  printf("La cantidad de palabras que terminan con la letra o es de %d", cant);
}

char ultimoCaracter(char string[])
{
  int size = strlen(string);
  return string[size - 1];
}