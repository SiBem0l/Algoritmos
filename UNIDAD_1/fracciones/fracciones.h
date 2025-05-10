#ifndef FRACCIONES_H
#define FRACCIONES_H

typedef struct{
    int num;
    int den;
}fraction;

///OPERACIONES BASICAS
//crear una fraccion y asignarle memoria
fraction* fraction_new(int num, int den);

//destruir el puntero y liberar la memoria 
void fraction_destroy(fraction* f);

//imprimir en consola una fraccion
void fraction_print(fraction* f);

//obtener el numerador y el denominador de una fraccion
int fraction_get_num(fraction* f);
int fraction_get_den(fraction* f);

///OPERACIONES MATEMATICAS
//suma de dos fracciones
fraction* fraction_add(fraction* f1, fraction* f2);

//resta de dos fracciones
fraction* fraction_sub(fraction* f1, fraction* f2);

//multiplicacion de dos fracciones
fraction* fraction_mult(fraction* f1, fraction* f2);

//division de dos fracciones
fraction* fraction_div(fraction* f1, fraction* f2);
fraction* fraction_inv(fraction* f);

//simplificar fracciones
void fraction_simplify(fraction* f);

//comparar fracciones
int fraction_cmp(fraction* f1, fraction* f2);

#endif
