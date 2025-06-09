#ifndef FUNC_H
#define FUNC_H

#include "ntree_basic.h"

ntn* create_ntree();
void add_sons(ntn* father, NTREE_ELEMENT a, NTREE_ELEMENT b);

void print(ntn* root);

#endif