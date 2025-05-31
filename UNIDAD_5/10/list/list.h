#ifndef LIST_H
#define LIST_H

#define LIST_ELEMENT int
#include "..\simple_node\node.c"

typedef struct{
    node* first_node;
    node** ptr_current_node;
    int elements;
    int max_elements;
}list;


list* list_new(int max_elements);

void list_append(list* l, LIST_ELEMENT new_element);
void list_insert(list* l, LIST_ELEMENT new_element);
void list_insertSort(list* l, LIST_ELEMENT new_element);

void list_cursorNext(list* l);
void list_cursorFirst(list* l);
void list_cursorEol(list* l);

void list_cursorRemove(list* l);
LIST_ELEMENT list_cursorGet(list* l);

void list_free(list* l);

int list_isEmpty(list* l);
int list_isFull(list* l);

#endif