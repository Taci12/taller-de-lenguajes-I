#include <stdio.h>
//! HACER UNION
typedef struct
{
  int red : 8;
  int green : 8;
  int blue : 8;
} rgb24;

typedef struct
{
  int red : 5;
  int green : 6;
  int blue : 5;
} rgb16;

rgb24 de_16_a_24(rgb16 color16);
rgb16 de_24_a_16(rgb24 color24);
void verBits(unsigned valor, unsigned bits);
void imprimir16(rgb16 color16);

int main()
{
  rgb16 color16;
  color16.red = 30;
  color16.green = 15;
  color16.blue = 3;
  rgb24 color24;
  color24.red = 200;
  color24.green = 59;
  color24.blue = 154;
  imprimir16(color16);
  printf("\n");
  imprimir24(color24);
  printf("\n");

  printf("Color de 24 truncado a 16:\n");
  rgb16 otroColor = de_24_a_16(color24);
  imprimir16(otroColor);

  printf("Color de 16 ampliado a 24:\n");
  rgb24 otroColor2 = de_16_a_24(otroColor);
  imprimir24(otroColor2);
}

void imprimir16(rgb16 color16)
{
  printf("Color 16 bits:\n");
  printf("red: ");
  verBits(color16.red, 5);
  printf("green: ");
  verBits(color16.green, 6);
  printf("blue: ");
  verBits(color16.blue, 5);
  printf("\n");
}

void imprimir24(rgb24 color24)
{
  printf("Color 24 bits:\n");
  printf("red: ");
  verBits(color24.red, 8);
  printf("green: ");
  verBits(color24.green, 8);
  printf("blue: ");
  verBits(color24.blue, 8);
  printf("\n");
}

void verBits(unsigned valor, unsigned bits)
{

  unsigned Mascara = 1 << bits - 1;

  for (int i = 1; i <= bits; i++)
  {
    putchar(valor & Mascara ? '1' : '0');
    valor = valor << 1;

    if (i % 8 == 0)
      putchar(' ');
  }
  putchar('\n');
}

rgb16 de_24_a_16(rgb24 color24)
{
  rgb16 color16;
  color24.red >>= 3;
  color16.red = color24.red;
  color24.green >>= 2;
  color16.green = color24.green;
  color24.blue >>= 3;
  color16.blue = color24.blue;
  return color16;
}

rgb24 de_16_a_24(rgb16 color16)
{
  rgb24 color24;
  color24.red = color16.red;
  color24.red <<= 3;
  color24.green = color16.green;
  color24.green <<= 2;
  color24.blue = color16.blue;
  color24.blue <<= 3;
  return color24;
}