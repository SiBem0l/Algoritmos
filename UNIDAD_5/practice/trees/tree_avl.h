#ifndef TREE_AVL_H
#define TREE_AVL_H

#include "tree_basic.h"

int btn_balanceFactor(btn* node);
int btn_isAVL(btn* root);
int btn_leftRotation(btn** ptr_node);
int btn_rightRotation(btn** ptr_node);
int btn_balanceTree(btn** ptr_root);
int _btn_balance(btn** ptr_node);

#endif // TREE_AVL_H