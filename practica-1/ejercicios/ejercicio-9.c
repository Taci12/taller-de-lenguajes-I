#include <stdio.h>

int main()
{
  float num1, num2;
  char operador;

  printf("Introduzca el primer numero:\n");
  scanf("%f", &num1);

  printf("Introduzca el operador:\n");
  scanf(" %c", &operador);
  while (!(operador == '+' || operador == '-' || operador == '*' || operador == '/'))
  {
    printf("Introduzca +, -, * o /:\n");
    scanf(" %c", &operador);
  }

  printf("Introduzca el segundo numero:\n");
  scanf("%f", &num2);

  switch (operador)
  {
  case '+':
    printf("El resultado es %.2f", num1 + num2);
    break;
  case '-':
    printf("El resultado es %.2f", num1 - num2);
    break;
  case '*':
    printf("El resultado es %.2f", num1 * num2);
    break;
  case '/':
    printf("El resultado es %.2f", num1 / num2);
    break;
  }
  return 0;
}