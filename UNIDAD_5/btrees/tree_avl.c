#include <stdio.h>
#include <math.h>

#include "tree_avl.h"

//AVL stands for the name of the authors
//Self balancing binary tree

//Factor de balance de un nodo. Mira si el nodo que se pasa esta balanceado
int btn_balanceFactor(btn* node){
    //BF =  H(izquierdo) - H(right)   
    int ans = 0;
    if(node){
        ans = btn_height(node->left) - btn_height(node->right);
    }
    return ans;
}

//Se fija si el arbol esta balanceado o no
int btn_isAVL(btn* root){
    //Balanced conditions: |BF(Ti)| < 2
    int is_balanced = 1;
    if(root){
        if((abs(btn_balanceFactor(root)) < 2)){
            if(btn_isAVL(root->left)){
                is_balanced = btn_isAVL(root->right);
            }
        }
    }
    return is_balanced;
}

//Rotacion izquierda de nodos
int btn_leftRotation(btn** ptr_node){
    int rotated = 0;
    if((*ptr_node) != NULL && (*ptr_node)->right != NULL){
        btn* aux = (*ptr_node)->right;
        (*ptr_node)->right = aux->left;
        aux->left = (*ptr_node);
        (*ptr_node) = aux;
        rotated = 1;
    }
    return rotated;
}

//Rotacion derecha de nodos
int btn_rightRotation(btn** ptr_node){
    int rotated = 0;
    if((*ptr_node) != NULL && (*ptr_node)->left != NULL){
        btn* aux = (*ptr_node)->left;
        (*ptr_node)->left = aux->right;
        aux->right = (*ptr_node);
        (*ptr_node) = aux;
        rotated = 1;
    }
    return rotated;
}

//Balancea arbol
int btn_balanceTree(btn** ptr_root){
    if(ptr_root != NULL && *ptr_root != NULL){
        btn_balanceTree(&((*ptr_root)->left));
        btn_balanceTree(&((*ptr_root)->right));
        _btn_balance(ptr_root);
    }
    return 1;
}
int _btn_balance(btn** ptr_node){
    int BF = btn_balanceFactor(*ptr_node);
    if(BF < -1){
        if(btn_balanceFactor((*ptr_node)->right) > 0){
            btn_rightRotation(& ((*ptr_node)->right) );
        }
        btn_leftRotation(ptr_node);
        _btn_balance(ptr_node);
    }else if(BF > 1){
        if(btn_balanceFactor((*ptr_node)->left) > 0){
            btn_leftRotation(& ((*ptr_node)->left) );
        }
        btn_rightRotation(ptr_node);
        _btn_balance(ptr_node);
    }
    if(abs(btn_balanceFactor(*ptr_node)) > 1){
        _btn_balance(ptr_node);
    }
    return 1;
}

//Inserta un nuevo nodo dejando el arbol balanceado
int btn_insertAVL(btn** ptr_root, BTREE_ELEM new_data){
    int added = 0;
    if(*ptr_root){
        btn_add(ptr_root, btn_create(new_data));
        if(!btn_isAVL){
            btn_balanceTree(ptr_root);
        }
        added = 1;
    }
    return added;
}

//Elimina un nodo dejandolo balanceado
int btn_rmvAVL(btn** ptr_root, BTREE_ELEM find){
    int removed = 0;
    if(*ptr_root){
        btn* removed_node = btn_rmvNode(ptr_root, find);
        if(btn_freeBranch(&removed_node)){
            btn_balanceTree(ptr_root);
            removed = 1;
        }
    }
    return removed;
}