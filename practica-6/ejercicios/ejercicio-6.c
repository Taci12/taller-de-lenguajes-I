#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.1415
#define AREA_CIRCULO(r) (PI * (r) * (r))

int main()
{
  srand(time(NULL));
  int i;
  int radio;
  for (i = 0; i < 10; i++)
  {
    radio = rand() % 20;
    printf("Area de radio %d: %.2f\n", radio, AREA_CIRCULO(radio));
  }
}