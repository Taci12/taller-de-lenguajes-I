#include <stdio.h>
#include "imath.h"

int potencia(int x, int y)
{
  int i;
  for (i = 1; i <= y; i++)
    x *= x;
  return x;
}

int cuadrado(int x)
{
  return x * x;
}

int cubo(int x)
{
  return x * x * x;
}

int absoluto(int x)
{
  if (x >= 0)
    return x;
  else
    return x * (-1);
}

int factorial(int x)
{
  if (x)
    return x * factorial(x - 1);
}

int sumatoria(int x)
{
  if (x == 0)
    return x;
  return x + sumatoria(x - 1);
}

int multiplo(int x, int y)
{
  return !(x % y);
}

int divisor(int x, int y)
{
  return !(y % x);
}

int par(int x)
{
  return !(x % 2);
}

int impar(int x)
{
  return (x % 2);
}