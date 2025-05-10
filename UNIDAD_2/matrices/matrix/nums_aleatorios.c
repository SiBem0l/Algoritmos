#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int int_rand(int min, int max);

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


/*
void fill_rand(vector* v, int min, int max){
    srand(time(NULL));
    for(int i = 0; i < v->max_size; i++){
        vector_add(v, int_rand(min, max));
    }
}
*/