#ifndef NODE_H
#define NODE_H

typedef struct _node{
    int data;
    struct _node* next;
}node;

node* node_create(int e);
node* add_front(node** h, node* new_node);
node* rmv_front(node** h);
node** find(node** h, int e);
node* insert_sort(node** h, node* new_node);
node* merge(node** h1, node** h2);
void *split(node** h, node** pares, node** impares);


#endif