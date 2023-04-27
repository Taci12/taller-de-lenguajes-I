#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i;
  srand((unsigned)time(NULL));
  for (i = 0; i <= 15; i++)
  {
    printf("El numero %d es %d\n", i, rand() % 50);
  }
}
