#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generar_operador()
{
  srand(time(NULL));
  int numero_aleatorio = rand() % 3;

  switch (numero_aleatorio)
  {
  case 0:
    return '+';
    break;
  case 1:
    return '-';
    break;
  case 2:
    return '*';
    break;
  case 3:
    return '/';
    break;
  }
}

void preguntar(int *nota)
{
  srand(time(NULL));
  int num1 = rand() % 100;
  int num2 = rand() % 100;
  int respuesta, respuesta_correcta;
  char operador = generar_operador();

  switch (operador)
  {
  case '+':
    respuesta_correcta = num1 + num2;
    break;
  case '-':
    respuesta_correcta = num1 - num2;
    break;
  case '*':
    respuesta_correcta = num1 * num2;
    break;
  case '/':
    respuesta_correcta = num1 / num2;
    break;
  }

  printf("Cuanto es %d %c %d ?\n", num1, operador, num2);
  scanf("%d", &respuesta);

  if (respuesta == respuesta_correcta)
  {
    printf("Correcto!\n");
    *nota += 1;
  }
  else
    printf("Incorrecto...\n");
}

int main()
{
  int i, nota = 0;
  for (i = 0; i < 5; i++)
  {
    preguntar(&nota);
  }
  switch (nota)
  {
  case 0:
    printf("Tu nota es una E\n");
    break;
  case 1:
    printf("Tu nota es una D\n");
    break;
  case 2:
    printf("Tu nota es una C\n");
    break;
  case 3:
    printf("Tu nota es una B\n");
    break;
  case 4:
    printf("Tu nota es una A\n");
    break;
  }
}