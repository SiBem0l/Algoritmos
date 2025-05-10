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

node* add_front(node** ptr_tail, node* new_node){
    if(new_node != NULL){
        if(*ptr_tail == NULL){ //Cuando la lista esta vacia
            new_node->next = new_node;
            *ptr_tail = new_node;
        }else{ //Cuando tiene elementos la lista
            new_node->next = (*ptr_tail)->next;
            (*ptr_tail)->next = new_node;
        }
    }
    return new_node;
}
node* add_back(node** ptr_tail, node* new_node){
    if(new_node != NULL){
        if(*ptr_tail == NULL){ //Cuando la lista esta vacia
            new_node->next = new_node;
            *ptr_tail = new_node;
        }else{ //Cuando tiene elementos la lista
            new_node->next = (*ptr_tail)->next;
            (*ptr_tail)->next = new_node;
            *ptr_tail = new_node;
        }
    }
    return new_node;
}

node* remove_front(node** ptr_node){
    if(*ptr_node == NULL) return NULL;
    node* aux = (*ptr_node)->next;
    (*ptr_node)->next = aux->next;
    aux->next = NULL;
    return aux;
}

node** find_pos(node* tail, int data){
    if(tail == NULL) return NULL;
    node* head = tail->next; //puntero a la cabeza
    node** result = &(tail->next); //direcciono a la cabeza

    while((*result)->data < data && (*result)->next != head){
        result = &(*result)->next;
    }
    if((*result)->data < data && (*result)->next == head){
        result = &(*result)->next;
    }
    return result;
}

node* insert_sort(node** ptr_tail, node* new_node){
    if(*ptr_tail == NULL){ // esta vacia la lista
        add_front(ptr_tail, new_node);
    }else{
        node** aux = find_pos(*ptr_tail, new_node->data);
        new_node->next = *aux;
        *aux = new_node;
    }
    return new_node;
}

/*
node* merge (node** h1, node** h2){
    node* result = *h1;
    *h1 = NULL;
    
    node* removed_node = remove_front(h2);
    while (removed_node != NULL){
        insert_sort(&result, removed_node);
        removed_node = remove_front(h2);
    }        
    return result;
}

void split(node** h, node** even, node** odd){
    *even = NULL;
    *odd = NULL;

    while(*h != NULL){
        node* removed_node = remove_front(h);
        if(removed_node->data % 2 == 0){ //par
            add_front(even, removed_node);
        }else{ //impar
            add_front(odd, removed_node);
        }
    }
}

void delete_all_with (node** h, int element){
    node** aux = find_pos(h, element);
    while(*aux != NULL && (*aux)->data == element){
        free(remove_front(aux));
        aux = find_pos(aux, element);
    }
}

void delete_duplicates (node** h) {
    while (*h != NULL) {
        delete_all_with(&(*h)->next, (*h)->data);
        h = &(*h)->next;  
    }
}
*/