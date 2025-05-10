#include "dnode.h"

dnode* dnode_create(int new_data){
    dnode* new_dnode = (dnode*)malloc(sizeof(dnode));
    new_dnode->data = new_data;
    new_dnode->prev = NULL;
    new_dnode->next = NULL;
}

dnode* add_front(dnode** ptr_dnode, dnode* new_dnode){
    if(*ptr_dnode == NULL) return NULL;
    new_dnode->next = *ptr_dnode;
    new_dnode->prev = NULL;
    return new_dnode;
}

dnode* remove_front(dnode** ptr_dnode){
    if(*ptr_dnode == NULL) return NULL;
    dnode* aux = *ptr_dnode;
    *ptr_dnode = (*ptr_dnode)->next;
    aux->next = NULL;
    aux->prev = NULL;
    (*ptr_dnode)->prev = NULL;
    return aux;
}

dnode** find_pos(dnode** ptr_dnode, int data){
    if(*ptr_dnode == NULL) return NULL;
    while((*ptr_dnode)->data < data && (*ptr_dnode)->next != NULL){
        ptr_dnode = &(*ptr_dnode)->next;
    }
    if((*ptr_dnode)->data < data && (*ptr_dnode)->next == NULL){
        ptr_dnode = &(*ptr_dnode)->next;
    }
    return ptr_dnode; //devuelvo puntero al node.next al anterior donde tendria que estar 
}

dnode* insert_sort(dnode** ptr_dnode, dnode* new_dnode){
    if(*ptr_dnode == NULL) return NULL;
    dnode** aux = find_pos(ptr_dnode, new_dnode->data);
    
    dnode* next_node = NULL;
    dnode* prev_node = NULL;
    
    next_node = *aux;
    prev_node = (*aux)->prev;

    *aux = new_dnode; //direcciono los nodos del costado
    next_node->prev = new_dnode;

    new_dnode->prev = prev_node; //direcciono el nuevo nodo
    new_dnode->next = next_node;

    return new_dnode;
}

void delete_all_with (dnode** h, int element){
    dnode** aux = find_pos(h, element);
    while(*aux != NULL && (*aux)->data == element){
        free(remove_front(aux));
        aux = find_pos(aux, element);
    }
}

dnode* merge (dnode** h1, dnode** h2){
    dnode* result = *h1;
    *h1 = NULL;
    
    dnode* removed_dnode = remove_front(h2);
    while (removed_dnode != NULL){
        insert_sort(&result, removed_dnode);
        removed_dnode = remove_front(h2);
    }        
    return result;
}