#include "./istack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  istack stack = s_create();
  s_push(&stack, 1);
  s_push(&stack, 2);
  s_push(&stack, 3);
  s_push(&stack, 4);
  s_push(&stack, 5);

  printf("size: %d\n", s_length(stack));
  printf("%d\n", s_pop(&stack));
  printf("%d\n", s_pop(&stack));
  printf("%d\n", s_pop(&stack));
  printf("%d\n", s_pop(&stack));
  printf("%d\n", s_pop(&stack));
}