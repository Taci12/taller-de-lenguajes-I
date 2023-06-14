#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 20

int contar(char string[]);
int contarOcurrencias(char string[], char caracter);
int contieneChar(char string[], char caracter);

int main()
{
  char string[DIM];
  printf("Introduzca una palabra:\n");
  scanf("%s", string);
  printf("La cantidad es %d\n", contar(string));
  return 0;
}

int contieneChar(char string[], char caracter)
{
  while (*string != '\0')
  {
    if (*string == caracter)
    {
      return 1;
    }
    string++;
  }
  return 0;
}

int contarOcurrencias(char string[], char caracter)
{
  int cant = 0;
  while (*string != '\0')
  {
    if (*string == caracter)
    {
      ++cant;
    }
    string++;
  }
  return cant;
}

int contar(char string[])
{
  char nuevaString[strlen(string)];
  char *ptrString;
  ptrString = string;

  int cantidad = 0;
  while (*ptrString != '\0')
  {
    if (!contieneChar(nuevaString, *ptrString))
    {
      cantidad += contarOcurrencias(string, *ptrString);
      strcat(nuevaString, ptrString);
    }
    ptrString++;
  }
  return cantidad;
}