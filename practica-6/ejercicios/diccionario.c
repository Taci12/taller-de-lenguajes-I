#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./diccionario.h"

diccionario crear_diccionario()
{
  diccionario dic;
  dic.puntero = NULL;
  dic.tamanio = 0;
  return dic;
}

int existe_palabra(diccionario dic, char *palabra)
{
  nodo *auxiliar;
  while ((auxiliar != NULL) && strcmp(auxiliar->palabra, palabra) > 0)
  {
    if (strcmp(auxiliar->palabra, palabra))
      return 1;
    auxiliar = auxiliar->siguiente;
  }
  return 0;
}

void agregar_palabra(diccionario *dic, char *palabra)
{
  if (!existe_palabra(*dic, palabra))
  {
    nodo *actual = dic->puntero;
    nodo *anterior = actual;
    nodo *nuevo = malloc(sizeof(nodo));
    strcpy(nuevo->palabra, palabra);
    while ((actual != NULL) && (strcmp(actual->palabra, palabra) > 0))
    {
      anterior = actual;
      actual = actual->siguiente;
    }
    // agrego en el inicio
    if (anterior = actual)
    {
      nuevo->siguiente = dic->puntero;
      dic->puntero = nuevo;
    }
    // agrego en el medio
    else
    {
      anterior->siguiente = nuevo;
      nuevo->siguiente = actual;
    }
  }
}
