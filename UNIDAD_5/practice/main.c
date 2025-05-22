#include <stdio.h>

#include "trees\tree_basic.c"

int main()
{
    btn* root = btn_create(1);

    btn_add(&root, btn_create(2));
    btn_add(&root, btn_create(3));
    btn_add(&root, btn_create(4));
    btn_add(&root, btn_create(5));
    btn_add(&root, btn_create(6));
    btn_add(&root, btn_create(7));
    btn_add(&root, btn_create(8));
    btn_add(&root, btn_create(9));

    btn_draw(root, toStr);

    btn_freeBranch(&root);
    return 0;
}