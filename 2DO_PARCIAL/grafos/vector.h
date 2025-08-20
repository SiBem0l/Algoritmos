#ifndef _VECTOR
#define _VECTOR

#define VECTOR_ELEMENT int

typedef struct _vector{
   VECTOR_ELEMENT* data;
   int size;
}vector;

vector* vector_new(int ini_size);
void vector_free(vector** ptr_v);
int vector_size(vector* v);
int vector_isempty(vector* v);
VECTOR_ELEMENT vector_seek(vector* v, int index);
VECTOR_ELEMENT vector_set(vector* v, int index, VECTOR_ELEMENT value);
int vector_add(vector* v, VECTOR_ELEMENT value);
VECTOR_ELEMENT vector_remove(vector* v, int index);
void vector_print(vector* v, void (*print)(VECTOR_ELEMENT));
void printInt(int num);

#endif