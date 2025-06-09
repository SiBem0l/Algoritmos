#include <stdio.h>
#include "func.h"
#include "queue.h"

//Crea el arbol pedido por la consigna
ntn* create_ntree(){
    //NIVEL 1
    ntn* root = ntn_new(10);
    //NIVEL 2
    add_sons(ntree_search(root, 10), 20, 24);
    //NIVEL 3
    add_sons(ntree_search(root, 20), 30, 32);
    add_sons(ntree_search(root, 21), 33, 33);
    add_sons(ntree_search(root, 22), 34, 34);
    add_sons(ntree_search(root, 24), 35, 35);
    //NIVEL 4
    add_sons(ntree_search(root, 34), 40, 46);
    
    return root;
}
//agrega todos hijos entre a y b
void add_sons(ntn* father, NTREE_ELEMENT a, NTREE_ELEMENT b){
    for(int i = a; i <= b; i++){
        ntn_addSon(father, ntn_new(i));
    }
}

//Imprime en amplitud mostrando el nivel de cada nodo
void print(ntn* root){
    queue* curr_level = queue_new(100);
    queue* next_level = queue_new(100);
    queue_enqueue(curr_level, root);
    for(int i = 1; queue_isEmpty(curr_level) == 0; i++){
        printf("NIVEL %d: ", i);
        while(queue_isEmpty(curr_level) == 0){
            ntn* node = queue_dequeue(curr_level);
            ntlist* curr_list = node->child;
            while(curr_list != NULL){
                queue_enqueue(next_level, curr_list->node);
                curr_list = curr_list->next;
            }
            printf("%d ", node->value);
        }
        queue* aux = curr_level; //guardo el puntero al stack ya vacio
        curr_level = next_level;
        next_level = aux;
        printf("\n");
    }
}

//Remueve un nodo remplazando por su hijo de mas a la izquierda
