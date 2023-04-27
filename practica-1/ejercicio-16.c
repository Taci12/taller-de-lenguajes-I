#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a; // guarda el valor de a
  *a = *b;  // almacena b en a
  *b = tmp; // almacena a en b
}

int main()
{
  int a = 5, b = 10;
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("Ejecuto funcion\n");
  swap(&a, &b);
  printf("a = %d\n", a);
  printf("b = %d\n", b);
}