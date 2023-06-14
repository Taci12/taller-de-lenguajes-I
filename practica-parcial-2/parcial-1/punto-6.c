#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    int i, j = argc;
    char *string = malloc(300 * sizeof(char));
    for (i = 1; i < j; i++)
    {
      strcat(string, argv[i]);
      strcat(string, " ");
    }
    printf("%s\n", string);
  }
  else
    printf("Argumentos insuficientes\n");
  return 0;
}