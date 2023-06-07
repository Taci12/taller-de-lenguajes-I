#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    int i, j = argc;
    for (i = 1; i < j; i++)
      printf("%s ", argv[i]);
    printf("\n");
  }
  return 0;
}