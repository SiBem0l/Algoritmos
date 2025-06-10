#ifndef GRAPH_H
#define GRAPH_H

#include "matrix.h"

typedef struct{
    matrix* adj_matrix;
    int n_vertex;
    int n_vertex_max;
}graph;

graph* graph_create(int n_vertex_max);
void graph_free(graph** ptr_g);

int graph_addVertex(graph* g, int n_new_vertex);

#endif