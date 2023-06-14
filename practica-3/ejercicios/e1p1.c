#include <stdio.h>
#define DIM 3

struct rectangulo
{
  float base;
  float altura;
};

void leerRectangulo(struct rectangulo *);
float area(struct rectangulo);

int main()
{
  struct rectangulo vector[DIM];
  int i, menorPosicion;
  struct rectangulo menor;
  menor.base = 9999;
  menor.altura = 9990;
  for (i = 0; i < DIM; i++)
  {
    leerRectangulo(&vector[i]);
    if (area(vector[i]) < area(menor))
    {
      menor = vector[i];
      menorPosicion = i;
    }
  }
  printf("Menor posicion: %d\n", menorPosicion);
}

void leerRectangulo(struct rectangulo *rectangulo)
{
  printf("Ingrese base:\n");
  scanf("%f", &rectangulo->base);
  printf("Ingrese altura:\n");
  scanf("%f", &rectangulo->altura);
}

float area(struct rectangulo rectangulo)
{
  return ((rectangulo.base) * (rectangulo.altura));
}
