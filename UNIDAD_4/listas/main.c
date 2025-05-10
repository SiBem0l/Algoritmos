#include <stdio.h>

#include "list\list.c"

int main()
{
    list* l = list_new(-1);
    list_insert(l, 1);
    list_insert(l, 2);
    list_append(l, 3);
    list_cursorEol(l);
    list_insert(l, 4);
    
    return 0;
}
