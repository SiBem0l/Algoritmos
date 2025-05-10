#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

typedef struct _vector{
   VECTOR_ELEMENT* a;
   int size;
   int max_size;
}vector;


///FUNCIONES BASICAS

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


///ORDENAMIENTO

/// @brief Ordena por metodo de burbuja un vector
/// @param vector
/// @param n_elementos
/// @param swap_crit 
void bubble_sort(VECTOR_ELEMENT* v, int n, int (*swap_crit)(VECTOR_ELEMENT a, VECTOR_ELEMENT b)){
    char swapped = 1;
    while((n > 0) && (swapped != 0)){
        swapped = 0;    
        for(int i = 1; i < n; i++){
            if(swap_crit(v[i-1], v[i])){
                swapped = 1; 
                swap(&v[i-1], &v[i]);
            }
        }
        n--;
    }
}
void swap(VECTOR_ELEMENT* a, VECTOR_ELEMENT* b){
    VECTOR_ELEMENT aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
//Criterios de comparaciones
int bigger (VECTOR_ELEMENT a, VECTOR_ELEMENT b){
    return (a > b);
}
int smaller (VECTOR_ELEMENT a, VECTOR_ELEMENT b){
    return (a < b);
}


///BUSQUEDA

/// @brief Busqueda de elemento en lista ordenada ascendente
/// @param key 
/// @param vector 
/// @param n_elementos 
/// @return element_index
int binary_search(int key, int* a, int n) {
    int low = 0; 
    int high = n - 1;  
    int mid = (high + low) / 2;
    while ((low < high) && (a[mid] != key)) {
        if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (high + low) / 2;
    }
    return (a[mid] == key) ? mid : n;
}


///AGREGAR ELEMENTOS EN LISTAS ORDENADAS

//0: se agrego correctamente
//1: error
int add_in_order(vector* v, VECTOR_ELEMENT new_element){
    if(v->size < v->max_size){
        int i = search_spot(new_element, v->a, v->size);
        vector_insert(v, i, new_element);
        return 0;
    }else{
        return 1;
    }
}
int search_spot(VECTOR_ELEMENT key, VECTOR_ELEMENT* a, int n){
    int low = 0; 
    int high = n - 1;  
    int mid = (high + low) / 2;
    while ((low < high) && (a[mid] != key)){
        if (key < a[mid]) {
            high = mid - 1;
        }else if(key > a[mid]){
            low = mid + 1;
        }
        mid = (high + low) / 2;
    }

    if(key < a[mid]){
        return mid;
    }else if(key > a[mid]){
        return mid+1;
    }
    return mid;
}

int add_v_in_order(vector* v, vector* v_new){
    int v_space = v->max_size - v->size;
    if(v_space > v_new->size){
        for(int i = 0; i < v_new->size; i++){
            add_in_order(v, v_new->a[i]);
        }
        return 0;
    }
    return 1;
}

int int_rand(int min, int max);
void fill_rand(vector* v, int min, int max);


///RANDOOOOOOOM
/**
 * @brief Devuelve un num aleatorio entre un min y un max
 * 
 * @param min
 * @param max
 * @return num_rand
 */
int int_rand(int min, int max){
    int num = rand() % (max+1-min) + min;
    return num;
}
void fill_rand(vector* v, int min, int max){
    srand(time(NULL));
    for(int i = 0; i < v->max_size; i++){
        vector_add(v, int_rand(min, max));
    }
}