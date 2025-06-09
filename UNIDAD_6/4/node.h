#ifndef NODE_H
#define NODE_H

#include "ntree_basic.h"
#define NODE_ELEMENT ntn*

typedef struct _node{
    NODE_ELEMENT data;
    struct _node* next;
}node;

node* node_create(NODE_ELEMENT new_data);
node* node_add_front(node** ptr_node, node* new_node);
node* node_remove_front(node** ptr_node);

#endif