#ifndef MATRIX_H
#define MATRIX_H

#define ELEMENT int
#define DEFAULT_ELEMENT 0

typedef struct{
    ELEMENT* elements; 
    int columns;
    int rows;
}matrix;

matrix* matrix_new(int rows, int columns);
void matrix_free(matrix** ptr_m);

int matrix_rows(matrix* m);
int matrix_columns(matrix* m);

ELEMENT matrix_get(matrix* m, int x, int y);
int matrix_set(matrix* m, int x, int y, ELEMENT value);

void matrix_copy(matrix* m_from, matrix* m_to);
int min(int a, int b);
int max(int a, int b);

void matrix_print(matrix* m, void prt(ELEMENT));
void print_int(int num);

void matrix_rand(matrix* m, const int MIN, const int MAX);
int int_rand(int min, int max);

#endif