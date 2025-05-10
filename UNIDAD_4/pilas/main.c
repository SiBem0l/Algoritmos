#include <stdio.h>

#include "stack\stack.c"

int main()
{
    stack* pile = stack_new(10);
    stack_push(pile, 1);
    stack_push(pile, 2);
    stack_push(pile, 3);
    STACK_ELEMENT element = stack_pop(pile);
    stack_push(pile, element);

    stack_destroy(&pile);

    return 0;
}
