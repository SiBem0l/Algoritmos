#include <stdio.h>
#include <stdlib.h>
#include "fracciones.h"

///OPERACIONES BASICAS
fraction* fraction_new(int num, int den){
    fraction* f = (fraction*)malloc(sizeof(fraction));
    f->num = num;
    f->den = den;
}

void fraction_destroy(fraction* f){
    free(f);
}

void fraction_print(fraction* f){
    printf("%d/%d\n", f->num, f->den);
}

int  fraction_get_num(fraction* f){
    int num = f->num;
    return num;
}

int  fraction_get_den(fraction* f){
    int den = f->den;
    return den;
}

///OPERACIONES MATEMATICAS
fraction* fraction_add(fraction* f1, fraction* f2){
    fraction* ans = fraction_new(0,0);
    ans->num = (f1->num)*(f2->den) + (f2->num)*(f1->den);
    ans->den = (f1->den)*(f2->den);
    fraction_simplify(ans);
    return ans;
}

fraction* fraction_sub(fraction* f1, fraction* f2){
    fraction* ans = fraction_new(0,0);
    ans->num = (f1->num)*(f2->den) - (f2->num)*(f1->den);
    ans->den = (f1->den)*(f2->den);
    fraction_simplify(ans);
    return ans;
}

fraction* fraction_mult(fraction* f1, fraction* f2){
    fraction* ans = fraction_new(0,0);
    ans->num = (f1->num)*(f2->num);
    ans->den = (f1->den)*(f2->den);
    fraction_simplify(ans);
    return ans;
}

fraction* fraction_div(fraction* f1, fraction* f2){
    fraction* ans = fraction_new(0,0);
    fraction* f2_inv = fraction_inv(f2);

    ans = fraction_mult(f1,f2_inv);

    fraction_destroy(f2_inv);
    fraction_simplify(ans);
    return ans;
}
fraction* fraction_inv(fraction* f){
    fraction* f_inv = fraction_new(f->den, f->num);
    return f_inv;
}

void fraction_simplify(fraction* f){
    int* num = &(f->num);
    int* den = &(f->den);

    if(*num == 0){
        *den = 1;
    }else{
        for(int i = 2; (i <= *num) && (i <= *den); i++){
            while (((*num%i) == 0) && ((*den%i) == 0))
            {
                *num = *num/i;
                *den = *den/i;
            }
        }
    }
}

int fraction_cmp(fraction* f1, fraction* f2){
    fraction_simplify(f1);
    fraction_simplify(f2);

    if((f1->num == f2->num) && (f1->den == f2->den)){
        return 1;
    }else{
        return 0;
    }
}