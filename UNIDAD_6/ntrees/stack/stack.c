#include "stack.h"


stack* stack_new(int max_elements){
    stack* new_s = (stack*)malloc(sizeof(stack));
    new_s->first_node = NULL;
    new_s->elements = 0;
    new_s->max_elements = max_elements;

    return new_s; 
}

void stack_push(stack* s, STACK_ELEMENT new_element){
    node** ptr_first_node = &(s->first_node);
    node_add_front(ptr_first_node, node_create(new_element));
    s->elements++; 
}
STACK_ELEMENT stack_pop(stack* s){
    node** ptr_first_node = &(s->first_node);
    node* removed_node = node_remove_front(ptr_first_node);
    STACK_ELEMENT popped_element = removed_node->data; //no estoy checkeando si tiene algo la first_nodea
    s->elements--;
    return popped_element; 
}

//Libera solo la memoria de una estructura. No siempre libera memoria interna (como nodos).
void stack_free(stack** ptr_s){
    free(*ptr_s);
    *ptr_s = NULL;
}
// Libera toda la memoria asociada, incluyendo elementos internos como nodos.
void stack_destroy(stack** ptr_s){
    stack* s = *ptr_s;
    while(!stack_isEmpty(s)){
        stack_pop(s);
    }
    stack_free(ptr_s);
}

int stack_isFull(stack* s){
    return s->elements >= s->max_elements;
}
int stack_isEmpty(stack* s){
    return s->elements == 0;
}

STACK_ELEMENT stack_top(stack* s){
    STACK_ELEMENT data = stack_pop(s);
    stack_push(s, data);
    return data;
}