#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc == 4)
  {
    int resultado = 0;
    char operador = argv[2][0];
    printf("%c\n", operador);
    int operando1 = atoi(argv[1]);
    int operando2 = atoi(argv[3]);

    switch (operador)
    {
    case '+':
      resultado = operando1 + operando2;
      break;
    case '-':
      resultado = operando1 - operando2;
      break;
    case '/':
      resultado = operando1 / operando2;
      break;
    case '.':
      resultado = operando1 * operando2;
      break;
    }
    printf("Resultado: %d\n", resultado);
  }
  else
    printf("No es un operador!!!");
}