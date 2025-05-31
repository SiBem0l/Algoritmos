#include <stdio.h>
#include "btrees_func.h"

int fusion(btn** ptr_root1, btn** ptr_root2){
    //recorro en post order el arbol 2
    if(*ptr_root2 == NULL) return 0;
 
 
    fusion(ptr_root1, & ((*ptr_root2)->left));
    fusion(ptr_root1, & ((*ptr_root2)->right));

    //saco el nodo de arbol 2 y lo inserto en el arbol 1
    btn_add(ptr_root1, rmv_leave(ptr_root2));

    return 1;
}
btn* rmv_leave(btn** ptr_leave){
    btn* removed_node = *ptr_leave;
    *ptr_leave = NULL;
    return removed_node;
}