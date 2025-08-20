#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list* list_new(){
    list* l = (list*)malloc(sizeof(list));
    l->firstNode = NULL;
    l->ptr_currentNode = &(l->firstNode);
    l->elements = 0;
    return l;
}

void list_free(list* l){
    free(l);
}

void list_append(list* l, LIST_ELEMENT new_element){
    node** ptr_cursor = l->ptr_currentNode; // guardo donde esta apuntando el cursor
    list_cursorEol(l);
    list_insert(l, new_element);
    l->ptr_currentNode = ptr_cursor;
}

void list_insert(list* l, LIST_ELEMENT new_element){
    node_add_front(l->ptr_currentNode, node_create(new_element));
    l->elements++;
}

//Apunta el cursor al siguiente, si no hay siguiente devuelve 0
int list_cursorNext(list* l){
    int last = 0;
    if(*(l->ptr_currentNode) != NULL){
        l->ptr_currentNode = &((*l->ptr_currentNode)->next);
    }
    return last;
}

void list_cursorFirst(list* l){
    l->ptr_currentNode = &(l->firstNode);
}

void list_cursorEol(list* l){
    node** ptr_currentNode = l->ptr_currentNode; //creo una variable local para trabajar
    while(*ptr_currentNode != NULL){
        node* current_node = *(ptr_currentNode);
        ptr_currentNode = &(current_node->next);
    }
    l->ptr_currentNode = ptr_currentNode; //descargo la variable a la lista
}

void list_cursorRemove(list* l){
    free(node_remove_front(l->ptr_currentNode));
}

LIST_ELEMENT list_cursorGet(list* l){
    node* removed_node = node_remove_front(l->ptr_currentNode);
    LIST_ELEMENT removed_data = removed_node->data;
    free(removed_node);
    return removed_data;
}

LIST_ELEMENT list_cursorSeek(list* l){
    return (*(l->ptr_currentNode))->data;
}

int list_cursorOnEOL(list* l){
    int isLast = 0;
    if(*(l->ptr_currentNode) == NULL){
        isLast = 1;
    }
    return isLast;
}

int list_size(list* l){
    return l->elements;
}

int list_isEmpty(list* l){
    return l->elements == 0;
}
