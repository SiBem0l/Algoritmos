#ifndef CIRCULAR_NODE_H
#define CIRCULAR_NODE_H

typedef struct _node{
    int data;
    struct _node* next;
}node;

node* node_create(int new_data);

node* add_front(node** ptr_tail, node* new_node);
node* add_back(node** ptr_tail, node* new_node);

node* remove_front(node** ptr_tail);
//removes front/back and returns the node removed

node** find_pos(node* ptr_tail, int data);
//returns pointer to the node.next where the data should be

node* insert_sort(node** ptr_node, node* new_node);
//returns pointer to the new node

// node* merge(node** h1, node** h2);
// //returns the list

// void split(node** h, node** even, node** odd);

// void delete_all_with (node** h, int element);

#endif