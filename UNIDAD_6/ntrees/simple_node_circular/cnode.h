#ifndef CIRCULAR_NODE_H
#define CIRCULAR_NODE_H

#include "..\ntree\ntree_basic.h"

#define CNODE_ELEMENT ntn*

typedef struct _cnode{
    CNODE_ELEMENT data;
    struct _cnode* next;
}cnode;

cnode* cnode_create(CNODE_ELEMENT new_data);

cnode* cnode_add_front(cnode** ptr_tail, cnode* new_node);
cnode* cnode_add_back(cnode** ptr_tail, cnode* new_node);

cnode* cnode_remove_front(cnode** ptr_tail);

cnode** cnode_find_pos(cnode* ptr_tail, CNODE_ELEMENT data);

cnode* cnode_insert_sort(cnode** ptr_tail, cnode* new_node);

#endif