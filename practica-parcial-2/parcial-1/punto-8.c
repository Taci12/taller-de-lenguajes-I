#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int dato;
  struct nodo *siguiente;
} lista;

void eliminar_elemento(lista **l, int elemento);

int main()
{
  lista *l = malloc(sizeof(lista));
}

// como nunca indica que es ordenada, asumo que no lo es
void eliminar_elemento(lista **l, int elemento)
{
  lista *anterior;
  lista *actual;
  actual = *l;
  anterior = actual;
  while ((actual->siguiente != NULL) && (actual->dato != elemento))
  {
    anterior = actual;
    actual = actual->siguiente;
  } // hola como estas~!!!!victoria mayer puto

  if (actual->dato == elemento)
  {
    if (actual == anterior)
    {
      *l = (*l)->siguiente;
      free(actual);
    }
    else
    {
      lista *auxiliar;
      auxiliar = actual;
      actual = actual->siguiente;
      anterior->siguiente = actual;
      free(auxiliar);
    }
  }
  else
    printf("El elemento no se encuentra en la lista");
}

void eliminar_lista(lista **l)
{
  if ((*l)->siguiente != NULL)
    eliminar_lista((*l)->siguiente);
  eliminar_elemento(l, (*l)->dato);
}
