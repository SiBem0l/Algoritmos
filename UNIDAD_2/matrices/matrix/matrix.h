#ifndef MATRIX_H
#define MATRIX_H

#define ELEMENT int

typedef struct
{
    ELEMENT* elements; 
    int columns;
    int rows;
}matrix;

matrix* matrix_new(int rows, int columns);
//Crea la matriz con el tamaño apropiado según las dimensiones establecidas.
void matrix_free(matrix* m); 
//Elimina la matriz
// int matrix_rows(matrix* m); 
// //Permite obtener la cantidad de filas
// int matrix_columns(matrix* m); 
// //Permite obtener la cantidad de columnas
// void* matrix_get(matrix* m, int row, int col);  
// //Permite obtener el valor de una posición de la matriz
void matrix_set(matrix* m, int row, int col, void* value);
//Permite reemplazar o asignar un elemento a la matriz
void matrix_print(matrix* m, void prt(void*)) ;
//Permite imprimir una matriz por consola

void matrix_fill_rand(matrix* m, const int MIN, const int MAX);
// //Llena de numeros aleatorios la matriz
#endif