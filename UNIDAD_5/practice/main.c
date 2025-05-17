#include <stdio.h>

#include "trees\tree_basic.c"

int main()
{
    btn* root = btn_create(1);

    int failed_adds = 0;
    failed_adds += btn_add(&root, btn_create(2));
    failed_adds += btn_add(&root, btn_create(3));
    failed_adds += btn_add(&root, btn_create(4));
    failed_adds += btn_add(&root, btn_create(5));
    failed_adds += btn_add(&root, btn_create(6));
    failed_adds += btn_add(&root, btn_create(7));
    failed_adds += btn_add(&root, btn_create(8));
    failed_adds += btn_add(&root, btn_create(9));

    btn_draw(root, toStr);

    btn_freeBranch(&root);
    return 0;
}