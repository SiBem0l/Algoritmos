#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node* node_create(int new_data){
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

node** node_find_pos(node** ptr_node, int data){
    if(*ptr_node == NULL) return NULL;
    while((*ptr_node)->data < data && (*ptr_node)->next != NULL){
        ptr_node = &(*ptr_node)->next;
    }
    if((*ptr_node)->data < data && (*ptr_node)->next == NULL){
        ptr_node = &(*ptr_node)->next;
    }
    return ptr_node; //devuelvo puntero al node.next al anterior donde tendria que estar 
}

node* node_insert_sort(node** ptr_node, node* new_node){
    if(*ptr_node == NULL) return NULL;
    node** aux = node_find_pos(ptr_node, new_node->data);
    new_node->next = *aux;
    *aux = new_node;
    return new_node;
}

node* node_merge (node** h1, node** h2){
    node* result = *h1;
    *h1 = NULL;
    
    node* removed_node = node_remove_front(h2);
    while (removed_node != NULL){
        node_insert_sort(&result, removed_node);
        removed_node = node_remove_front(h2);
    }        
    return result;
}

void node_split(node** h, node** even, node** odd){
    *even = NULL;
    *odd = NULL;

    while(*h != NULL){
        node* removed_node = node_remove_front(h);
        if(removed_node->data % 2 == 0){ //par
            node_add_front(even, removed_node);
        }else{ //impar
            node_add_front(odd, removed_node);
        }
    }
}

void node_delete_all_with (node** h, int element){
    node** aux = node_find_pos(h, element);
    while(*aux != NULL && (*aux)->data == element){
        free(node_remove_front(aux));
        aux = node_find_pos(aux, element);
    }
}

void node_delete_duplicates (node** h) {
    while (*h != NULL) {
        node_delete_all_with(&(*h)->next, (*h)->data);
        h = &(*h)->next;  
    }
}