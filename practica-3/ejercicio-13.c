#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum dispositivos
{
  vibrar,
  linterna,
  trasera,
  frontal,
  datos,
  gps,
  wifi,
  bluetooth
};

// corro el bit a apagar para ubicarlo en el lugar correcto
// lo invierto con Ca1
// hago un and al lugar que quiero
void apagar(unsigned *celular, int dispositivo)
{
  int lugar = (1 << dispositivo);
  ~lugar;
  *celular &= lugar;
}

void prender(unsigned *celular, int dispositivo)
{
  int lugar = 1 << dispositivo;
  *celular |= lugar;
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

void invertir(unsigned *celular, unsigned posicion)
{
  unsigned lugar = (1 << posicion);
  *celular ^= lugar;
}

void main()
{
  unsigned celular = (0 << 8);
  prender(&celular, wifi);
  prender(&celular, frontal);
  verBits(celular, 8);
  apagar(&celular, wifi);
  verBits(celular, 8);
  invertir(&celular, wifi);
  verBits(celular, 8);
}