#ifndef _VECTOR
#define _VECTOR

#define VECTOR_ELEMENT int

typedef struct _vector vector;

vector* vector_new(int ini_size);
// Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño
// Máximo = ini_size.

void vector_free(vector* v);
// Eliminar el vector

int vector_size(vector* v);
// Permite obtener el tamaño actual del vector

int vector_isfull(vector* v);
// Devuelve 0 si no está lleno y 1 si está lleno.

int vector_isempty(vector* v);
// Devuelve 0 si no está vacío y 1 si está vacío.

VECTOR_ELEMENT vector_get(vector* v, int index);
// Permite obtener el valor de una posición del vector

VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value);
// Permite reemplazar el valor de una posición del vector

int vector_add(vector* v, VECTOR_ELEMENT value);
// Permite agregar un elemento al final

int vector_insert(vector* v, int index, VECTOR_ELEMENT value);
// Permite agregar un elemento en una posición determinada.

VECTOR_ELEMENT vector_remove(vector* v, int index);
// Permite eliminar un elemento del vector

void vector_print(vector* v, void (*print)(VECTOR_ELEMENT));
void print_int(int num);
// Permite imprimir un vector por consola

///ORDENAMIENTO
void bubble_sort(VECTOR_ELEMENT* v, int n, int (*swap_crit)(VECTOR_ELEMENT a, VECTOR_ELEMENT b));
void swap(VECTOR_ELEMENT* a, VECTOR_ELEMENT* b);
int bigger (VECTOR_ELEMENT a, VECTOR_ELEMENT b);
int smaller (VECTOR_ELEMENT a, VECTOR_ELEMENT b);

///BUSQUEDA
int binary_search(int key, int* a, int n);

///AGREGAR ELEMENTOS EN LISTAS ORDENADAS
int add_in_order(vector* v, VECTOR_ELEMENT new_element);
int search_spot(VECTOR_ELEMENT key, VECTOR_ELEMENT* a, int n);
int add_v_in_order(vector* v, vector* v_new);

///RAAAANDOOOM
int int_rand(int min, int max);
void fill_rand(vector* v, int min, int max);



#endif