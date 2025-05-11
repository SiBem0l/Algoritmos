#ifndef TREE_H
#define TREE_H

#define BTREE_ELEM int

typedef struct _btn {
    BTREE_ELEM data;
    struct _btn *left;
    struct _btn *right;
}btn;

btn* btn_create(BTREE_ELEM new_data);
void btn_print(btn* root);
btn** btn_find(btn** ptr_btn, BTREE_ELEM data_find, int cmp(BTREE_ELEM, BTREE_ELEM));
int cmp_minMax(BTREE_ELEM a, BTREE_ELEM b);
int btn_add(btn** ptr_root, btn* new_btn, int cmp(BTREE_ELEM, BTREE_ELEM));
btn* btn_rmvBranch(btn** ptr_node);
void btn_freeBranch(btn** ptr_node);
btn* btn_rmvNode(btn** ptr_root, BTREE_ELEM data_find, int cmp(BTREE_ELEM, BTREE_ELEM));
int btn_size(btn* root);

#endif