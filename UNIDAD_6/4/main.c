#include <stdio.h>
#include "func.h"

int main()
{
    ntn* root = create_ntree();

    ntn_remove(&root);

    print_amplitud(root);
    print(root);
    return 0;
}
