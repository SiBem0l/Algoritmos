#include <stdio.h>

#include "trees\tree.c"

int main()
{
    btn* root = btn_create(10);
    btn_add(&root, btn_create(5), cmp_minMax);
    btn_freeBranch(&root);
    return 0;
}