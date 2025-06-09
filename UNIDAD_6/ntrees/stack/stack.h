#ifndef STACK_H
#define STACK_H

#include "../simple_node/node.c"

#define STACK_ELEMENT NODE_ELEMENT

typedef struct{
    node* first_node;
    int elements;
    int max_elements;
}stack;

stack* stack_new(int max_elements);
void stack_push(stack* s, STACK_ELEMENT new_element);
STACK_ELEMENT stack_pop(stack* s);
void stack_free(stack** s);
void stack_destroy(stack** s);
int stack_isFull(stack* s);
int stack_isEmpty(stack* s);


#endif