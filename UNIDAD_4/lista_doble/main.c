#include <stdio.h>
#include "double_node\dnode.c"

int main()
{
    dnode* a = dnode_create(4);
    insert_sort(&a, dnode_create(1));
    insert_sort(&a, dnode_create(1));
    insert_sort(&a, dnode_create(2));
    
    delete_all_with(&a, 1);

    return 0;
}
