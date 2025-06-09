#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_new(int max_elements){
    queue* new_queue = (queue*)malloc(sizeof(queue));
    new_queue->max_elements = max_elements;
    new_queue->elements = 0;
    new_queue->tail = NULL;
}

void queue_enqueue(queue* q, QUEUE_ELEMENT new_element){
    cnode** ptr_tail = &(q->tail);
    cnode_add_back(ptr_tail, cnode_create(new_element));
    q->elements++;
}
QUEUE_ELEMENT queue_dequeue(queue* q){
    
    cnode** ptr_tail = &(q->tail);
    cnode* removed_cnode = cnode_remove_front(ptr_tail);
    QUEUE_ELEMENT removed_data = removed_cnode->data;
    q->elements--;
    free(removed_cnode);
    return removed_data;
}

//libera la struct pero no los nodos
void queue_free(queue** ptr_q){
    free(*ptr_q);
    *ptr_q = NULL;
}
//libera todo
void queue_destroy(queue** ptr_q){
    queue* q = *ptr_q;
    while(!queue_isEmpty(q)){
        queue_dequeue(q);
    }
    queue_free(ptr_q);
}

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