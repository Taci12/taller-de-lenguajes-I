#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 50

typedef struct
{
    int numero;
    char palo[10];
} carta;

carta *generarMazo();
void mezclarMazo(carta mazo[50]);

int main()
{
    carta *mazo = generarMazo();
    mezclarMazo(mazo);
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("numero: %d\n", mazo[i].numero);
        printf("palo: %s\n", mazo[i].palo);
    }
    return 0;
}

void mezclarMazo(carta mazo[50])
{
    srand(time(NULL));
    int i;
    for (i = 0; i < 50; i++)
    {
        int nuevoIndice = rand() % 50;
        carta aux = mazo[i];
        mazo[i] = mazo[nuevoIndice];
        mazo[nuevoIndice] = aux;
    }
}

carta *generarMazo()
{
    carta vector[50];
    int i, j, pos;
    char oro[5] = "oro";
    char basto[10] = "basto";
    char espada[10] = "espada";
    char copa[10] = "copa";

    for (j = 1; j <= 4; j++)
    {
        for (i = 1; i <= 12; i++)
        {
            pos = (i * j) - 1;
            vector[pos].numero = i;
            switch (j)
            {
            case 1:
                strcpy(vector[pos].palo, oro);
                break;

            case 2:
                strcpy(vector[pos].palo, basto);
                break;

            case 3:
                strcpy(vector[pos].palo, espada);
                break;

            case 4:
                strcpy(vector[pos].palo, copa);
                break;
            }
        }
    }
    char comodin[10] = "comodin";
    vector[48].numero = 0;
    strcpy(vector[48].palo, comodin);
    vector[49].numero = 0;
    strcpy(vector[49].palo, comodin);
    return &vector
}