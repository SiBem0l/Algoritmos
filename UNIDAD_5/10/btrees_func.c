#include <stdio.h>
#include "btrees_func.h"
#include "list\list.h"

//Armar 3 funciones para devolver el contenido de un árbol en un vector: 
//en inorder, preorder y post order. 
list* toList(btn* root, void order(btn* root, list* l)){
    if(root == NULL) return 0;
    list* l = list_new(btn_size(root));
    order(root, l);
    return l;
}
void inOrder(btn* root, list* l){
    if(root != NULL){
        inOrder(root->left, l);
        list_append(l, (int)(root->data));
        inOrder(root->right, l);
    } 
}
void postOrder(btn* root, list* l){
    if(root != NULL){
        postOrder(root->left, l);
        postOrder(root->right, l);
        list_append(l, (int)(root->data));
    } 
}
void preOrder(btn* root, list* l){
    if(root != NULL){
        list_append(l, (int)(root->data));
        preOrder(root->left, l);
        preOrder(root->right, l);
    }
}
