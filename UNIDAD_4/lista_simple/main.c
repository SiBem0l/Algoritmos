#include <stdio.h>
#include "simple_node/node.c"

int main()
{
    node* a1 = node_create(2);
    
    node* a2 = node_create(20);
    
    insert_sort(&a2, node_create(48));
    insert_sort(&a2, node_create(81));
    insert_sort(&a2, node_create(1));
    insert_sort(&a2, node_create(2));

    a1 = merge(&a1, &a2);

    node* aux = a1;
    while(aux != NULL){
        printf("%d ", aux->data);
        aux = aux->next;
    }

    return 0;
}
