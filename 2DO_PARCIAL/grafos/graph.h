#ifndef GRAPH_H
#define GRAPH_H

#include "matrix.h"
#include "list.h"
#include "vector.h"
#include "queue.h"

//This is only for graphs without weight
#define CONNECTED 1
#define DISCONNECTED 0

typedef struct _graph{
    matrix* adjMatrix;
    int nVertex;
    int nVertexMax;
}graph;

graph* graph_create(int nVertexMax);
void graph_free(graph** ptr_g);

int graph_addVertex(graph* g, int nNewVertex);
void graph_removeVertex(graph* g, int vertexToRemove);

int digraph_setAdj(graph* g, int vertexOrigin, int vertexDestination, int value);
int graph_setAdj(graph* g, int vertexOrigin, int vertexDestination, int value);
int graph_getAdj(graph* g, int vertexOrigin, int vertexDestination);
void graph_copyAdj(graph* gFrom, int vertexOriginFrom, int vertexDestinationFrom, graph* gTo, int vertexOriginTo, int vertexDestinationTo);

list* graph_getAdjList(graph* g, int vertexOrigin);

void graph_printAdj(graph* graphToPrint);
void graph_printAdjList(list* adjList);
void graph_printLevels(graph* g, int vertexOrigin);
void graph_printDepth(graph* g, int vertexOrigin);
void _printDepth(graph* g, int currentVertex, vector* visited);

int graph_degreeExit(graph* g, int vertex);

#endif