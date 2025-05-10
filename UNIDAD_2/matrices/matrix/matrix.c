#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "nums_aleatorios.c"

matrix* matrix_new(int rows, int columns){
    matrix* m = (matrix*)malloc(sizeof(matrix));
    m->elements = (ELEMENT*)malloc(sizeof(ELEMENT)*columns*rows);
}

void matrix_free(matrix* m){
    free(m->elements);
    free(m);
}

void matrix_print(matrix* m, void prt(void*)){
    int linear_index = 0;
    for(int y = 0; y < m->rows; y++){
        for(int x = 0; x < m->columns; x++){
            linear_index = x + y*m->columns;
            prt(m->elements[linear_index]);
        }
        printf("\n");
    }
}
void print_int(void* num){
    printf("%d ", *((int*)num));
}

void matrix_set(matrix* m, int row, int col, void* value){
    int linear_index = col + row*m->columns;
    memcpy((void*)(m->elements[linear_index]), value, sizeof(ELEMENT));
}


void matrix_fill_rand(matrix* m, const int MIN, const int MAX){
    for(int x = 0; x < m->columns; x++){
        for(int y = 0; y < m->elements; y++){
            int num = int_rand(MIN, MAX);
            matrix_set(m, y, x, (void*)&num);
        }
    }
}
