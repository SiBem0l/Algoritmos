#include <stdlib.h>
#include <string.h>

#include "tree_basic.h"


//FUNCIONES PARA CREAR Y ELIMINAR ELEMENTOS

//Crea un nuevo nodo
btn* btn_create(BTREE_ELEM new_data){
    btn* new_btn = (btn*)malloc(sizeof(btn));
    if(new_btn != NULL){
        new_btn->data = new_data;
        new_btn->left = NULL;
        new_btn->right = NULL;
    }
    return new_btn;
}

//Imprime in order en consola como texto
void btn_print(btn* root){ //printed in order
    if(root != NULL){
        btn_print(root->left);
        printf("%d ", root->data);
        btn_print(root->right);
    }
}

//Añade al elemento si es que no esta, en caso de no estar devuelve 0 la funcion
int btn_add(btn** ptr_root, btn* new_btn){
    int flag_added = 0;
    if(new_btn != NULL){
        btn** position = btn_find(ptr_root, new_btn->data);
        if(*position == NULL){
            *position = new_btn;
            flag_added = 1;
        }
    } 
    return flag_added;
}

//Devuelve el nodo con todo lo que tenga enganchado
btn* btn_rmvBranch(btn** ptr_node){
    btn* aux = *ptr_node;
    *ptr_node = NULL; 
    return aux;
} 

//Elimina al nodo con todo lo que tenga enganchado
void btn_freeBranch(btn** ptr_node){
    btn* node = *ptr_node;
    if(node != NULL){
        btn_freeBranch(&(node->left));
        btn_freeBranch(&(node->right));
        free(node);
    }
    *ptr_node = NULL;
}

//Busca al elemnto que se pide y lo elimina del arbol
btn* btn_rmvNode(btn** ptr_root, BTREE_ELEM data_find){
    btn* removed_node = NULL;
    btn** ptr_found = btn_find(ptr_root, data_find);
    if(*ptr_found != NULL){
        removed_node = *ptr_found;
        btn_add( &((*ptr_found)->right), (*ptr_found)->left);
        *ptr_found = (*ptr_found)->left;
        removed_node->left = NULL;
        removed_node->right = NULL;
    }
    return removed_node;
}



//FUNCIONES DE BUSQUEDA Y CONTEO

//Contiene al elemento find
int btn_contains(btn* root, BTREE_ELEM find){
    int ans = 0; //por default el numero no esta
    if(root != NULL){
        if(find < root->data){
            ans = btn_contains(root->left, find);
        }else if(find > root->data){
            ans = btn_contains(root->right, find);
        }else{
            ans = 1;
        }
    }
    return ans;
}

//Busca el puntero que es igual a data_find o devuelve donde deberia de estar ese elemento
btn** btn_find(btn** ptr_btn, BTREE_ELEM data_find){
    while(*ptr_btn != NULL && (*ptr_btn)->data != data_find){
        if(data_find < (*ptr_btn)->data){ // el dato es menor
            ptr_btn = &((*ptr_btn)->left);
        }else if(data_find > (*ptr_btn)->data){ //el dato es mayor
            ptr_btn = &((*ptr_btn)->right);
        }
    }
    return ptr_btn;
}

//Cantidad de nodos en el arbol
int btn_size(btn* root){
    int suma = 0;
    if(root != NULL){
        suma += btn_size(root->left);
        suma += btn_size(root->right);
        suma++;
    }
    return suma;
}

//Altura de un nodo
int btn_height(btn* node){
    int height_left = 0;
    int height_right = 0;
    if(node != NULL){
        height_left = btn_height(node->left) + 1;
        height_right = btn_height(node->right) + 1;
    }
    return _max_value(height_left, height_right);
}
int _max_value(BTREE_ELEM a, BTREE_ELEM b){
    int ans = 0;
    if(a > b){
        ans = a;
    }else{
        ans = b;
    }
    return ans;
}

//Nivel del nodo                          default = 1 
int btn_level(btn* node, BTREE_ELEM data, int curr_level){
    int ans = 0;
    if(node){
        if(node->data != data){
            if(data < node->data){
                ans = btn_level(node->left, data, curr_level + 1);
            }else{
                ans = btn_level(node->right, data, curr_level + 1);
            }
        }else{
            ans = curr_level;
        }
    }
    return ans;
}


//ADICIONALES

//Funcion dibujar arboles en consola
void btn_draw(btn *tree, void toStr (btn*, char*)){
    char s[20][255];
    for (int i = 0; i < 20; i++) sprintf(s[i], "%80s", " ");

    _btn_print(tree, 0, 0, 0, s, toStr);

    for (int i = 0; i < 20; i++) {
        int j = 0;
        while (s[i][j] != '\0' && s[i][j] == ' ') {
            j++;
        }
        if (s[i][j] != '\0') {
            printf("%s\n", s[i]);
        }
    }
    printf("\n\n");
}

//Funcion interna para dibujar el arbol
//Esta funcion se encarga de meter el dibujo dentro de una matriz que simula la consola
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*)){
    char b[200];
    int width = 5;

    if (!tree) return 0;
    toStr(tree, b); //b pasa a ser el numero convertido a string
    //sprintf(b, "%s", str);
    

    int left = _btn_print(tree->left, 1, offset, depth + 1, s, toStr);
    int right = _btn_print(tree->right, 0, offset + left + width, depth + 1, s, toStr);

    //for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++) s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth && !is_left) {
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }
    
    return left + width + right;
}

void toStr(btn* node, char* s){
    sprintf(s, " %03d", node->data);
}