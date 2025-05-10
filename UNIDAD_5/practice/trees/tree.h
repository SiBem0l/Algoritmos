#ifndef TREE_H
#define TREE_H

#define BTREE_ELEM int

typedef struct _btn {
    BTREE_ELEM data;
    struct _btn *left;
    struct _btn *right;
}btn;

btn* btn_create(BTREE_ELEM new_data);

#endif