#include <stdio.h>
#include "queue.h"

int main()
{
    queue* q = queue_new(100);
    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);

    queue_dequeue(q);
    queue_dequeue(q);
    queue_dequeue(q);
    
    return 0;
}
