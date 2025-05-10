#include "node.h"

#define NULL 0

node* node_create(int e)
{
    node* new_node;
    new_node = (node*)malloc(sizeof(node));

    if(new_node){
        new_node->data = e;
        new_node->next = NULL;
        return new_node;
    }
}
node* rmv_front(node** head){
    if(*head==NULL) return NULL;
    node* aux = (*head)->next;
    (*head)->next = NULL;
    node* remove = (*head);
    (*head)= aux;
    return remove;
}
node** find(node** h, int e){
    if(*h != NULL) return NULL;
    while((*h)->data < e){
        h = &(*h)->next;
    }
    return h;
}
node* insert_sort(node** h, node* new_node){
    if(new_node != NULL){
        node** aux = find(h,new_node->data);
        new_node->next = *aux;
        *aux = new_node;    
    }
    return new_node;
}
node* merge(node** h1, node** h2){
    node* r = *h1;
    *h1 = NULL;
    while(insert_sort(&r,rmv_front(h2)));
    return r;
} //Hace de nuevo de manera eficiente recorriendo las dos listas al mismo tiempo

//Eliminar los elementos repetidos en la lista
//split pares impares