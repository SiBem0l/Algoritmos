#ifndef QUEUE_H
#define QUEUE_H

#include "cnode.h"

#define QUEUE_ELEMENT CNODE_ELEMENT

typedef struct{
    cnode* tail;
    int elements;
    int max_elements;
}queue;

queue* queue_new(int max_elements);
void queue_enqueue(queue* q, QUEUE_ELEMENT new_element);
QUEUE_ELEMENT queue_dequeue(queue* q);
void queue_free(queue** ptr_q);
void queue_destroy(queue** ptr_q);
QUEUE_ELEMENT queue_peek(queue* q);
int queue_isFull(queue* q);
int queue_isEmpty(queue* q);

#endif