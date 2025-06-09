#include <stdio.h>
#include "ntree\ntree_basic.c"

int main()
{
    //Creo el arbol
    ntn* ntree = ntn_new(0);
    ntn_addSon(ntree, ntn_new(1));
    ntn_addSon(ntree, ntn_new(2));
    ntn_addSon(ntree, ntn_new(3));
    ntn_addSon(ntree->child->node, ntn_new(10));
    ntn_addSon(ntree->child->node, ntn_new(20));
    
    ntn* node = ntree_search(ntree, 10);

    return 0;
}
