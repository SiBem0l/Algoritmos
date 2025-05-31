#ifndef NODE_H
#define NODE_H

typedef struct _node{
    int data;
    struct _node* next;
}node;

node* node_create(int new_data);

node* node_add_front(node** ptr_node, node* new_node);

node* node_remove_front(node** ptr_node);
//removes front and returns the node removed

node** node_find_pos(node** ptr_node, int data);
//returns pointer to the node.next where the data should be

node* node_insert_sort(node** ptr_node, node* new_node);
//returns pointer to the new node

node* node_merge(node** h1, node** h2);
//returns the list

void node_split(node** h, node** even, node** odd);

void node_delete_all_with (node** h, int element);


#endif