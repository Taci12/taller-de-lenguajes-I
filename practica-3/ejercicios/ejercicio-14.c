#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void barajarMazo(carta mazo);
carta sacarCarta(carta mazo);
void imprimirCarta(carta c);
carta *generarMazo();

typedef struct
{
  int numero : 4;
  int palo : 3;

} carta;

enum palos
{
  COMODIN,
  ORO,
  COPA,
  ESPADA,
  BASTO
};

int main()
{
}

carta sacarCarta(carta mazo[])
{
}

void imprimirCarta(carta c)
{
  printf("%d de %d", c.numero, c.palo);
}

carta *generarMazo()
{
  carta mazo[50];
  int i, j, pos;
  for (i = ORO; i <= BASTO; i++)
  {
    for (j = 1; j <= 12; j++)
    {
      pos = (i * j) - 1;
      mazo[pos].numero = j;
      mazo[pos].palo = i;
    }
  }
  mazo[48].numero = COMODIN;
  mazo[48].palo = COMODIN;
  mazo[49].numero = COMODIN;
  mazo[49].palo = COMODIN;
}