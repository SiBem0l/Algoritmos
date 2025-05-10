#include <stdio.h>
#include "simple_node_circular\circular_node.c"

int main()
{
    node* a_tail = NULL;
    insert_sort(&a_tail, node_create(-2));
    insert_sort(&a_tail, node_create(-1));
    insert_sort(&a_tail, node_create(0));
    insert_sort(&a_tail, node_create(1));
    insert_sort(&a_tail, node_create(2));
    

    return 0;
}
