#ifndef LIST_H
#define LIST_H

#include "node.h"

#define LIST_ELEMENT NODE_ELEMENT

typedef struct{
    node* firstNode;
    node** ptr_currentNode;
    int elements;
}list;

list* list_new();
void list_free(list* l);

void list_append(list* l, LIST_ELEMENT new_element);
void list_insert(list* l, LIST_ELEMENT new_element);
void list_insertSort(list* l, LIST_ELEMENT new_element);

int list_cursorNext(list* l);
void list_cursorFirst(list* l);
void list_cursorEol(list* l);

void list_cursorRemove(list* l);
LIST_ELEMENT list_cursorGet(list* l);
LIST_ELEMENT list_cursorSeek(list* l);
int list_cursorOnEOL(list* l);

int list_size(list* list);
int list_isEmpty(list* l);

#endif