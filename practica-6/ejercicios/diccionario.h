#ifndef DICCIONARIO_H_DEFINED
#define DICCIONARIO_H_DEFINED

struct nodo
{
  char *palabra;
  struct nodo *siguiente;
};

typedef struct nodo nodo;

struct diccionario
{
  int tamanio;
  nodo *puntero;
};

typedef struct diccionario diccionario;

diccionario crear_diccionario();
int existe_palabra(diccionario dic, char *palabra);
void agregar_palabra(diccionario *dic, char *palabra);
#endif