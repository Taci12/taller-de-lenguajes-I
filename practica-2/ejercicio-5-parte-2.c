#include <stdio.h>
#define DIM 4

void swap(int *a, int *b);
void invertir(int vector[]);
void imprimirVector(int vector[]);

int main()
{
  int vector[DIM] = {1, 2, 3, 4};
  printf("Antes:\n");
  imprimirVector(vector);
  printf("\n");
  invertir(vector);
  printf("Despues\n");
  imprimirVector(vector);
  printf("\n");
}

void imprimirVector(int vector[])
{
  int i;
  printf("vector = ");
  for (i = 0; i < DIM; i++)
  {
    printf(" %d ", vector[i]);
  }
}

void invertir(int vector[])
{
  int i, j;
  for (i = 0; i < DIM; i++)
  {
    for (j = 0; j < DIM - (i + 1); j++)
    {
      swap(&vector[j], &vector[j + 1]);
    }
  }
}
// 1 2 3 4
// 2 3 4 1
// 3 4 2 1
// 4 3 2 1
void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}