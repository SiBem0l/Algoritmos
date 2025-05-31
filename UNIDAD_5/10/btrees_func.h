#ifndef BTREES_FUNC_H
#define BTREES_FUNC_H

#include "..\btrees\tree_basic.h"
#include "list\list.h"

list* toList(btn* root, void order(btn* root, list* l));
void inOrder(btn* root, list* l);
void postOrder(btn* root, list* l);
void preOrder(btn* root, list* l);

#endif