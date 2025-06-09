#include <stdio.h>
#include <stdlib.h>

#include "cnode.h"

cnode* cnode_create(CNODE_ELEMENT new_data){
    cnode* new_cnode = (cnode*)malloc(sizeof(cnode));
    if(new_cnode == NULL){
        return NULL;    
    }else{
        new_cnode->data = new_data;
        new_cnode->next = NULL;
        return new_cnode;    
    }
}

cnode* cnode_add_front(cnode** ptr_tail, cnode* new_cnode){
    if(new_cnode != NULL){
        if(*ptr_tail == NULL){ //Cuando la lista esta vacia
            new_cnode->next = new_cnode;
            *ptr_tail = new_cnode;
        }else{ //Cuando tiene elementos la lista
            new_cnode->next = (*ptr_tail)->next;
            (*ptr_tail)->next = new_cnode;
        }
    }
    return new_cnode;
}
cnode* cnode_add_back(cnode** ptr_tail, cnode* new_cnode){
    if(new_cnode != NULL){
        if(*ptr_tail == NULL){ //Cuando la lista esta vacia
            new_cnode->next = new_cnode;
            *ptr_tail = new_cnode;
        }else{ //Cuando tiene elementos la lista
            new_cnode->next = (*ptr_tail)->next;
            (*ptr_tail)->next = new_cnode;
            *ptr_tail = new_cnode;
        }
    }
    return new_cnode;
}

//removes front/back and returns the cnode removed
cnode* cnode_remove_front(cnode** ptr_tail){
    if(*ptr_tail == NULL) return NULL;
    cnode* aux = (*ptr_tail)->next;
    (*ptr_tail)->next = aux->next;
    aux->next = NULL;
    return aux;
}

//(ONLY FOR TYPE INT) Returns pointer to the cnode.next where the data should be
cnode** cnode_find_pos(cnode* tail, CNODE_ELEMENT data){
    if(tail == NULL) return NULL;
    cnode* head = tail->next; //puntero a la cabeza
    cnode** result = &(tail->next); //direcciono a la cabeza

    while((*result)->data < data && (*result)->next != head){
        result = &(*result)->next;
    }
    if((*result)->data < data && (*result)->next == head){
        result = &(*result)->next;
    }
    return result;
}

//(ONLY FOR TYPE INT) returns pointer to the new cnode
cnode* cnode_insert_sort(cnode** ptr_tail, cnode* new_cnode){
    if(*ptr_tail == NULL){ // esta vacia la lista
        cnode_add_front(ptr_tail, new_cnode);
    }else{
        cnode** aux = cnode_find_pos(*ptr_tail, new_cnode->data);
        new_cnode->next = *aux;
        *aux = new_cnode;
    }
    return new_cnode;
}