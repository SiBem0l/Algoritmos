#include <stdio.h>

#include "vectores/vector.c"

int main()
{
    vector* v1 = vector_new(10);

    vector_add(v1,1);
    vector_add(v1,2);
    vector_add(v1,4);
    vector_add(v1,7);

    vector_set(v1,0,56);
    vector_insert(v1,0,23);
    vector_remove(v1,0);

    void (*print_ptr)(VECTOR_ELEMENT);
    print_ptr = print_int;
    vector_print(v1 ,print_ptr);

    vector_free(v1);
    return 0;
}
