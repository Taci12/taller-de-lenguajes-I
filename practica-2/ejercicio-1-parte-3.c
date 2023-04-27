#include <stdio.h>
#define DIM 15

int main()
{
  char input[DIM] = "holaaaa";
  int cant = 0;
  while (strcmp(input, "ZZZ"))
  {
    printf("Introduzca una string:\n");
    scanf("%s", input);
    if (strlen(input) == 5)
      cant++;
  }
  printf("La cantidad de palabras de longitud 5 es de %d", cant);
}