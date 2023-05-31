#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc == 5)
  {
    float resultado = 0;
    for (int i = 1; i < 5; i++)
      resultado += atoi(argv[i]);
    resultado /= 4;
    printf("El promedio es: %.2f\n", resultado);
  }
}