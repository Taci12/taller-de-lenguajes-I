#ifndef ISTACK_H_DEFINED
#define ISTACK_H_DEFINED

struct node
{
  int data;
  struct node *next;
};

typedef struct node node;

struct istack
{
  node *top;
  int size;
};

typedef struct istack istack;

istack s_create();
int s_push(istack *stack, int number);
int s_pop(istack *stack);
int s_top(istack stack);
int s_empty(istack stack);
int s_length(istack stack);
#endif