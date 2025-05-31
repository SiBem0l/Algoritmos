#include <stdio.h>
#include "..\btrees\tree_basic.c"
#include "btrees_func.c"

int main(int argc, char const *argv[])
{
    btn* root1 = btn_create(10);
    btn* root2 = btn_create(100);

    btn_add(&root1, btn_create(5));
    btn_add(&root1, btn_create(15));

    btn_add(&root2, btn_create(23));
    btn_add(&root2, btn_create(27));
    btn_add(&root2, btn_create(65));

    fusion(&root1, &root2);

    btn_draw(root1, toStr);

    btn_freeBranch(&root1);
    btn_freeBranch(&root2);

    return 0;
}
