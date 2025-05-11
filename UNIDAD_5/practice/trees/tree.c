#include <stdlib.h>

#include "tree.h"

btn* btn_create(BTREE_ELEM new_data){
    btn* new_btn = (btn*)malloc(sizeof(btn));
    if(new_btn != NULL){
        new_btn->data = new_data;
        new_btn->left = NULL;
        new_btn->right = NULL;
        return new_btn;
    }
    return new_btn;
}

void btn_print(btn* root){ //printed in order
    if(root != NULL){
        btn_print(root->left);
        printf("%d", root->data);
        btn_print(root->right);
    }
}

btn** btn_find(btn** ptr_btn, BTREE_ELEM data_find, int cmp(BTREE_ELEM, BTREE_ELEM)){
    while(*ptr_btn != NULL){
        if(cmp(data_find, (*ptr_btn)->data) == -1){ // el dato es menor
            ptr_btn = &((*ptr_btn)->left);
        }else if(cmp(data_find, (*ptr_btn)->data) == 1){ //el dato es mayor
            ptr_btn = &((*ptr_btn)->right);
        }
    }
    return ptr_btn;
}
int cmp_minMax(BTREE_ELEM a, BTREE_ELEM b){
    int ans = 0;
    if(a < b){
        ans = -1;
    }else if(a > b){
        ans = 1;
    }
    return ans;
}

int btn_add(btn** ptr_root, btn* new_btn, int cmp(BTREE_ELEM, BTREE_ELEM)){
    int flag_added = 0;
    if(new_btn != NULL){
        btn** position = btn_find(ptr_root, new_btn->data, cmp);
        if(*position == NULL){
            *position == new_btn;
            flag_added = 1;
        }
    } 
    return flag_added;
} //si devuelve 0 es porque ya se encuentra ese elemento en la lista

btn* btn_rmvBranch(btn** ptr_node){
    btn* aux = *ptr_node;
    *ptr_node = NULL; 
} //lo saca del branch
void btn_freeBranch(btn** ptr_node){
    btn* node = *ptr_node;
    if(node != NULL){
        btn_freeBranch(&(node->left));
        btn_freeBranch(&(node->right));
        free(node);
    }
    *ptr_node = NULL;
} //elimina todo el branch

btn* btn_rmvNode(btn** ptr_root, BTREE_ELEM data_find, int cmp(BTREE_ELEM, BTREE_ELEM)){
    btn* removed_node = NULL;
    btn** ptr_found = btn_find(ptr_root, data_find, cmp);
    if(*ptr_found != NULL){
        removed_node = *ptr_found;
        btn_add( &((*ptr_found)->right), (*ptr_found)->left, cmp);
        *ptr_found = (*ptr_found)->left;
        removed_node->left = NULL;
        removed_node->right = NULL;
    }
    return removed_node;
}

int btn_size(btn* root){
    int suma = 0;
    if(root != NULL){
        suma += btn_size(root->left);
        suma += btn_size(root->right);
        suma++;
    }
    return suma;
}

//Devolver la profundidad de un nodo. La profundidad de un nodo es 1 más la profundidad de su padre.
//Considerar 0 (cero) la profundidad de la raíz.