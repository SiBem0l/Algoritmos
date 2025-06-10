#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"

//Crea la matriz con el tamaño apropiado según las dimensiones establecidas.
matrix* matrix_new(int rows, int columns){
    matrix* m = (matrix*)malloc(sizeof(matrix));
    if(m != NULL){
        //creo espacio para los elementos de la matriz y los igualo a 0
        m->elements = (ELEMENT*)calloc(columns*rows, sizeof(ELEMENT));
        if(m->elements != NULL){
            m->columns = columns;
            m->rows = rows;
        }else{
            free(m);
            m = NULL;
        }
    }
    return m;
}

//Elimina una matriz
void matrix_free(matrix** ptr_m){
    free((*ptr_m)->elements);
    (*ptr_m)->elements = NULL;
    free(*ptr_m);
    *ptr_m = NULL;
}

//Obtine cantidad de columnas/filas
int matrix_rows(matrix* m){
    return m->rows;
}
int matrix_columns(matrix* m){
    return m->columns;
}

//Devuelve el valor del elemento en la posicion pedida
ELEMENT matrix_get(matrix* m, int x, int y){
    if(x > m->columns || y > m->rows) return DEFAULT_ELEMENT;
    int linear_index = y*(m->columns) + x;
    return m->elements[linear_index];
}

//Permite reemplazar o asignar un elemento a la matriz
int matrix_set(matrix* m, int x, int y, ELEMENT value){
    if(x > m->columns || y > m->rows) return 0;
    int linear_index = x + y*(m->columns);
    m->elements[linear_index] = value;
    return 1;
}

//Copia la matrix cortando en los limites
void matrix_copy(matrix* m_from, matrix* m_to){
    int columns_min = min(m_from->columns, m_to->columns);
    int rows_min = min(m_from->rows, m_to->rows);
    for(int y = 0; y < rows_min; y++){
        for(int x = 0; x < columns_min; x++){
            matrix_set(m_to, x, y, matrix_get(m_from, x, y));
        }
    }
}
int min(int a, int b){
    int ans = b;
    if(a < b){
        ans = a;
    }
    return ans;
}


void matrix_print(matrix* m, void prt(ELEMENT)){
    int linear_index = 0;
    for(int y = 0; y < m->rows; y++){
        for(int x = 0; x < m->columns; x++){
            linear_index = x + y*m->columns;
            prt(m->elements[linear_index]);
        }
        printf("\n");
    }
}
void print_int(int num){
    printf("%d ", num);
}

void matrix_rand(matrix* m, const int MIN, const int MAX){
    for(int x = 0; x < m->columns; x++){
        for(int y = 0; y < m->rows; y++){
            matrix_set(m, x, y, int_rand(MIN, MAX));
        }
    }
}
//Devuelve un num aleatorio entre un min y un max
int int_rand(int min, int max){
    int num = rand() % (max+1-min) + min;
    return num;
}
