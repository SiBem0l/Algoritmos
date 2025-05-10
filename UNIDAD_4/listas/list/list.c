#include <stdio.h>

#include "list.h"

list* list_new(int max_elements){
    list* l = (list*)malloc(sizeof(list));
    l->first_node = NULL;
    l->ptr_current_node = &(l->first_node);
    l->elements = 0;
    l->max_elements = max_elements;
    return l;
}

void list_append(list* l, LIST_ELEMENT new_element){
    node** ptr_cursor = l->ptr_current_node; // guardo donde esta apuntando el cursor
    list_cursorEol(l);
    list_insert(l, new_element);
    l->ptr_current_node = ptr_cursor;
}
void list_insert(list* l, LIST_ELEMENT new_element){
    node_add_front(l->ptr_current_node, node_create(new_element));
    l->elements++;
}
void list_insertSort(list* l, LIST_ELEMENT new_element){
    node** ptr_first_node = &(l->first_node);
    node_insert_sort(ptr_first_node, node_create(new_element));
    l->elements++;
}

void list_cursorNext(list* l){
    node* current_node = *(l->ptr_current_node);
    l->ptr_current_node = &(current_node->next);
}
void list_cursorFirst(list* l){
    l->ptr_current_node = &(l->first_node);
}
void list_cursorEol(list* l){
    node** ptr_current_node = l->ptr_current_node; //creo una variable local para trabajar
    while(*ptr_current_node != NULL){
        node* current_node = *(ptr_current_node);
        ptr_current_node = &(current_node->next);
    }
    l->ptr_current_node = ptr_current_node; //descargo la variable a la lista
}

void list_cursorRemove(list* l){
    free(node_remove_front(l->ptr_current_node));
}
LIST_ELEMENT list_cursorGet(list* l){
    node* removed_node = node_remove_front(l->ptr_current_node);
    LIST_ELEMENT removed_data = removed_node->data;
    free(removed_node);
    return removed_data;
}

void list_free(list* l){
    free(l);
}

int list_isEmpty(list* l){
    return l->elements == 0;
}
int list_isFull(list* l){
    return l->elements >= l->max_elements;
}

/*
Básicas: insert./append. - first./next./eol.(end of list) - get./remove.

Adicionales: insert_sort. is_empty. is_full.

Otras: new. free length destroy
*/
