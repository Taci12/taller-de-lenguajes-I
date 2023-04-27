#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.141592653589793

enum identificadores
{
  circulo,
  elipse,
  triangulo,
  cuadrado,
  rectangulo
};

typedef struct
{
  float radio;

} sCirculo;

typedef struct
{
  float radioMayor;
  float radioMenor;
} sElipse;

typedef struct
{
  float base;
  float altura;
} sTriangulo;

typedef struct
{
  float lado;
} sCuadrado;

typedef struct
{
  float base, altura;
} sRectangulo;

typedef union
{
  sCirculo circulo;
  sElipse elipse;
  sTriangulo triangulo;
  sCuadrado cuadrado;
  sRectangulo rectangulo;
} uFigura;

typedef struct
{
  uFigura figura;
  unsigned id;
} sFigura;

float calcularArea(sFigura figuraLoquisima);
void leerFigura(sFigura *);

int main()
{
  sFigura figuraInput;
  leerFigura(&figuraInput);
  printf("%.2f", calcularArea(figuraInput));
  return 0;
}

void leerFigura(sFigura *figura)
{
  int input;
  printf("circulo = 0,\n elipse = 1, \n triangulo = 2, \n cuadrado = 3, \n rectangulo = 4\n Figura:\n");
  scanf("%d", &input);
  switch (input)
  {
  case circulo:
    printf("Radio:\n");
    scanf("%f", &figura->figura.circulo.radio);
    break;

  case elipse:
    printf("Radio mayor:\n");
    scanf("%f", &figura->figura.elipse.radioMayor);
    printf("Radio menor:\n");
    scanf("%f", &figura->figura.elipse.radioMenor);
    break;

  case triangulo:
    printf("Base:\n");
    scanf("%f", &figura->figura.triangulo.base);
    printf("Altura:\n");
    scanf("%f", &figura->figura.triangulo.altura);
    break;

  case cuadrado:
    printf("Lado:\n");
    scanf("%f", &figura->figura.cuadrado.lado);
    break;

  case rectangulo:
    printf("Base:\n");
    scanf("%f", &figura->figura.rectangulo.base);
    printf("Altura:\n");
    scanf("%f", &figura->figura.rectangulo.altura);
    break;
  }
}

float calcularArea(sFigura figuraLoquisima)
{
  switch (figuraLoquisima.id)
  {
  case circulo:
    return (float)(PI * figuraLoquisima.figura.circulo.radio * figuraLoquisima.figura.circulo.radio);
    break;

  case elipse:
    return (float)(PI * figuraLoquisima.figura.elipse.radioMenor * figuraLoquisima.figura.elipse.radioMayor);
    break;

  case triangulo:
    return (float)((figuraLoquisima.figura.triangulo.base * figuraLoquisima.figura.triangulo.altura) / 2);
    break;

  case cuadrado:
    return (float)(figuraLoquisima.figura.cuadrado.lado * figuraLoquisima.figura.cuadrado.lado);
    break;
  case rectangulo:
    return (figuraLoquisima.figura.rectangulo.base * figuraLoquisima.figura.rectangulo.altura);
    break;
  }
}