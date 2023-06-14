#include <stdio.h>
#include <string.h>
#define DIM 20

int esCapicuaIndice(char string[]);
int esCapicuaPuntero(char string[]);

int main()
{
  char palabraCapicua[DIM] = "rotor";
  char palabra[DIM] = "rotooooor";
  printf("%d\n", esCapicuaIndice(palabraCapicua));
  printf("%d\n", esCapicuaPuntero(palabraCapicua));
  printf("%d\n", esCapicuaIndice(palabra));
  printf("%d\n", esCapicuaPuntero(palabra));
  return 0;
}

int esCapicuaIndice(char string[])
{
  char stringReves[strlen(string)];
  int i, j;
  for (i = strlen(string), j = 0; i > 0; i--, j++)
  {
    stringReves[j] = string[i];
  }
  if (!strcmp(string, stringReves))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int esCapicuaPuntero(char string[])
{
  char stringReves[strlen(string)];
  char *ptrString;
  ptrString = string;
  int i, longitud = strlen(string);
  for (i = 0; i < longitud; i++)
  {
    string++;
  }

  for (i = 0; i < longitud; i++)
  {
    *stringReves = *string;
    stringReves++;
    string--;
  }

  if (!strcmp(ptrString, stringReves))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}