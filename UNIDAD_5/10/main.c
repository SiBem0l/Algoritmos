#include <stdio.h>
#include "..\btrees\tree_basic.c"
#include "list\list.c"
#include "btrees_func.c"

int main(int argc, char const *argv[])
{
    btn* root = btn_create(10);

    btn_add(&root, btn_create(5));
    btn_add(&root, btn_create(15));
    btn_add(&root, btn_create(23));
    btn_add(&root, btn_create(27));
    btn_add(&root, btn_create(65));

    btn_draw(root, toStr);
    list* l = toList(root, postOrder);

    btn_freeBranch(&root);
    return 0;
}
