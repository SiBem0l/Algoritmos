#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct _vector{
   VECTOR_ELEMENT* a;
   int size;
   int max_size;
} vector;


/**
 * @brief Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño Máximo = ini_size.
 * 
 * @param ini_size 
 * @return vector* 
 */
vector* vector_new(int ini_size){
   vector* v;
   v = (vector*)malloc(sizeof(vector));

   v->a = (VECTOR_ELEMENT*)malloc(sizeof(VECTOR_ELEMENT)*ini_size);
   v->size = 0;
   v->max_size = ini_size;
   return v;
}

/**
 * @brief Eliminar el vector
 * 
 * @param v 
 */
void vector_free(vector* v){
    free(v->a);
    free(v);
} 

/**
 * @brief Permite obtener el tamaño actual del vector
 * 
 * @param v 
 * @return int 
 */
int vector_size(vector* v){
   return v->size;
}

/**
 * @brief Devuelve 0 si no está lleno y 1 si está lleno. 
 * 
 * @param v 
 * @return int 
 */
int vector_isfull(vector* v){
    if(v->max_size == v->size){
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief Devuelve 0 si no está vacío y 1 si está vacío. 
 * 
 * @param v 
 * @return int 
 */
int vector_isempty(vector* v){
    if(v->size == 0){
        return 1;
    }else{
        return 0;
    }
}


/**
 * @brief Permite obtener el valor de una posición del vector
 * 
 * @param v 
 * @param index 
 * @return VECTOR_ELEMENT 
 */
VECTOR_ELEMENT vector_get(vector* v, int index){
    return (v->a)[index]; 
}  


/**
 * @brief Permite reemplazar el valor de una posición del vector
 * 
 * @param v 
 * @param index 
 * @return VECTOR_ELEMENT 
 */
VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value){
    v->a[index] = value;
}

/**
 * @brief Permite agregar un elemento al final
 * 
 * @param v 
 * @param value 
 */
int vector_add(vector* v, VECTOR_ELEMENT value){
    if(vector_isfull(v)){
        return 1;
    }else{
        v->a[v->size] = value;
        (v->size)++;
        return 0; 
    }
}


/**
 * @brief Permite agregar un elemento en una posición determinada.
 * 
 * @param v 
 * @param index 
 * @param value 
 */
int vector_insert(vector* v, int index, VECTOR_ELEMENT value){
    if(vector_isfull(v)){
        return 1;
    }else if((index < 0) && (index >= v->max_size)){
        return 1;
    }else{
        for(int i = (v->size - 1); i >= index; i--){
            v->a[i+1] = v->a[i];
        }
        v->a[index] = value;
        (v->size)++;
    }
}


/**
 * @brief Permite eliminar un elemento del vector
 * 
 * @param v 
 * @param index 
 */
VECTOR_ELEMENT vector_remove(vector* v, int index){
    for(int i = index; i < v->size; i++){
        v->a[i] = v->a[i+1]; 
    }
    v->size--;
}

/**
 * @brief print the vector
 * 
 */
void vector_print(vector* v, void (*print)(VECTOR_ELEMENT)){
    for(int i = 0; i < v->size; i++){
        print(v->a[i]);
    }
}
void print_int(int num){
    printf("Numero: %d\n", num);
}