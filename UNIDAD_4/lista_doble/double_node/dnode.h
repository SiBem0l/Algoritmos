#ifndef DNODE_H
#define DNODE_H

#include "stdio.h"
#include "stdlib.h"

#define LIST_ELEMENT int

typedef struct _dnode {
    LIST_ELEMENT data;
    struct _dnode* prev;
    struct _dnode* next;
} dnode;

dnode* dnode_create(int new_ddata);

dnode* add_front(dnode** ptr_dnode, dnode* new_dnode);

dnode* remove_front(dnode** ptr_dnode);
//removes front and returns the node removed

dnode** find_pos(dnode** ptr_dnode, int data);
//returns pointer to the node.next where the data should be


dnode* insert_sort(dnode** ptr_dnode, dnode* new_dnode);
//returns pointer to the new node

void delete_all_with (dnode** h, int element);

dnode* merge(dnode** h1, dnode** h2);
//returns the list


/*
void split(node** h, node** even, node** odd);
*/

#endif