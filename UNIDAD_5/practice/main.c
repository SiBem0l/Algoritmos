#include <stdio.h>

#include "trees\tree_basic.c"
#include "trees\tree_avl.c"

int main()
{
    btn* root = btn_create(1);

    for(int i = 0; i < 14; i++){
        btn_add(&root, btn_create(i));
    }

    btn_draw(root, toStr);
    btn_balanceTree(&root);
    btn_draw(root, toStr);

    btn_freeBranch(&root);
    return 0;
}