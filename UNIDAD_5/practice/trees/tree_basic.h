#ifndef TREE_BASIC_H
#define TREE_BASIC_H

#define BTREE_ELEM int

typedef struct _btn {
    BTREE_ELEM data;
    struct _btn *left;
    struct _btn *right;
}btn;

//FUNCIONES PARA CREAR Y ELIMINAR ELEMENTOS
btn* btn_create(BTREE_ELEM new_data);
void btn_print(btn* root);
int btn_add(btn** ptr_root, btn* new_btn);
btn* btn_rmvBranch(btn** ptr_node);
void btn_freeBranch(btn** ptr_node);
btn* btn_rmvNode(btn** ptr_root, BTREE_ELEM data_find);

//FUNCIONES DE BUSQUEDA Y CONTEO
int btn_contains(btn* root, BTREE_ELEM find);
int btn_size(btn* root);
btn** btn_find(btn** ptr_btn, BTREE_ELEM data_find);
int btn_height(btn* node);
int _max_value(BTREE_ELEM a, BTREE_ELEM b);

//ADICIONALES
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*));
void btn_draw(btn *tree, void toStr (btn*, char*));
void toStr(btn* node, char* s);

#endif