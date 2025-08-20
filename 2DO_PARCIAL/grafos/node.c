#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node* node_create(NODE_ELEMENT new_data){
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL){
        return NULL;    
    }else{
        new_node->data = new_data;
        new_node->next = NULL;
        return new_node;    
    }
}

node* node_add_front(node** ptr_node, node* new_node){ 
    if(*ptr_node == NULL){
        new_node->next = NULL;
        *ptr_node = new_node;
    }else{ //(*ptr_node != NULL)
        new_node->next = *ptr_node;
        *ptr_node = new_node;
    }
    return new_node;
}

node* node_remove_front(node** ptr_node){
    if(*ptr_node == NULL) return NULL;
    node* aux = (*ptr_node)->next;
    (*ptr_node)->next = NULL; //ya no puede referenciar a la lista
    node* removed = *ptr_node;
    *ptr_node = aux; 
    return removed;
}