#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

istack s_create()
{
  istack stack;
  stack.top = malloc(sizeof(node));
  stack.size = 0;
  return stack;
}

int s_push(istack *stack, int number)
{
  node *new;
  new = malloc(sizeof(node));
  new->data = number;
  new->next = stack->top;
  stack->top = new;
  stack->size++;
  return number;
}

int s_pop(istack *stack)
{
  int element = stack->top->data;
  node *aux = stack->top;
  stack->top = stack->top->next;
  free(aux);
  stack->size--;
  return element;
}

int s_top(istack stack)
{
  return stack.top->data;
}

int s_empty(istack stack)
{
  if (!stack.size)
    return 0;
  else
    return 1;
}

int s_length(istack stack)
{
  return stack.size;
}