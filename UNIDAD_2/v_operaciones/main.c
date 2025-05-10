#include <stdio.h>

#include "vectores\vector.c"

int main()
{
    vector* v1 = vector_new(10);
    vector* v2 = vector_new(10);

    //Llenar de aleatorios
    //fill_rand(v1, 0, 1000);
    //fill_rand(v2, 0, 10);
    vector_add(v1, 2);
    vector_add(v2, 8);
    vector_add(v2, 1);
    vector_add(v2, 4);
    

    bubble_sort(v1->a, v1->size, bigger);
    bubble_sort(v2->a, v2->size, bigger);

    vector_print(v1, print_int);
    printf("\n\n---------------------------------------------\n\n");
    vector_print(v2, print_int);
    
    printf("\n\n---------------------------------------------\n\n");
    printf("\n\n---------------------------------------------\n\n");

    printf("Agregar numero el v2 (1:no se pudo / 0:se pudo): %d\n\n", add_v_in_order(v1, v2));

    vector_print(v1, print_int);
    printf("\n\n---------------------------------------------\n\n");


    return 0;
}

