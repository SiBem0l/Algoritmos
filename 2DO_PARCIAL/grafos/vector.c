#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector* vector_new(int ini_size){
   vector* v;
   v = (vector*)malloc(sizeof(vector));

   v->data = (VECTOR_ELEMENT*)calloc(ini_size, sizeof(VECTOR_ELEMENT));
   v->size = ini_size;
   return v;
}

void vector_free(vector** ptr_v){
    free((*ptr_v)->data);
    free(*ptr_v);
    *ptr_v = NULL;
} 

int vector_size(vector* v){
   return v->size;
}

int vector_isempty(vector* v){
    if(v->size == 0){
        return 1;
    }else{
        return 0;
    }
}

VECTOR_ELEMENT vector_seek(vector* v, int index){
    return (v->data)[index]; 
}  

VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value){
    v->data[index] = value;
}

VECTOR_ELEMENT vector_remove(vector* v, int index){
    for(int i = index; i < v->size; i++){
        v->data[i] = v->data[i+1]; 
    }
    v->size--;
}

void vector_print(vector* v, void (*print)(VECTOR_ELEMENT)){
    for(int i = 0; i < v->size; i++){
        print(v->data[i]);
    }
}
void printInt(int num){
    printf("Numero: %d\n", num);
}