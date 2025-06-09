#include <stdio.h>
#include "func.h"

int main()
{
    ntn* root = create_ntree();
    print_amplitud(root);
    print(root);
    return 0;
}
