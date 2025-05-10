#include <stdio.h>

#include "queue\queue.c"

int main()
{
    queue* q = queue_new(10);
    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);
    queue_enqueue(q, 4);
    QUEUE_ELEMENT element = queue_dequeue(q);
    queue_enqueue(q, element);

    queue_destroy(&q);
    
    return 0;
}
