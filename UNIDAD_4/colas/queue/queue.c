#include <stdio.h>

#include "queue.h"

queue* queue_new(int max_elements){
    queue* new_queue = (queue*)malloc(sizeof(queue));
    new_queue->max_elements = max_elements;
    new_queue->elements = 0;
    new_queue->tail = NULL;
}

void queue_enqueue(queue* q, QUEUE_ELEMENT new_element){
    node** ptr_tail = &(q->tail);
    node_add_back(ptr_tail, node_create(new_element));
    q->elements++;
}
QUEUE_ELEMENT queue_dequeue(queue* q){
    node** ptr_tail = &(q->tail);
    node* removed_node = node_remove_front(ptr_tail);
    QUEUE_ELEMENT removed_data = removed_node->data;
    q->elements--;
    free(removed_node);
    return removed_data;
}

void queue_free(queue** ptr_q){
    free(*ptr_q);
    *ptr_q = NULL;
}
//libera la struct pero no los nodos
void queue_destroy(queue** ptr_q){
    queue* q = *ptr_q;
    while(!queue_isEmpty(q)){
        queue_dequeue(q);
    }
    queue_free(ptr_q);
}
//libera todo

QUEUE_ELEMENT queue_peek(queue* q){
    QUEUE_ELEMENT data = queue_dequeue(q);
    queue_enqueue(q, data);
    return data;
}

int queue_isFull(queue* q){
    return q->elements >= q->max_elements;
}
int queue_isEmpty(queue* q){
    return q->elements == 0;
}

/*
Básicas: enqueue. dequeue.

Adicionales: peek. is_full. is_empty

Otras: new. free. length destroy.
*/