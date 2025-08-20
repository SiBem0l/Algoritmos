#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

graph* graph_create(int nVertexMax){
    graph* newGraph = (graph*)malloc(sizeof(graph));
    if(newGraph != NULL){
        //creo la matriz y la lleno de 0
        newGraph->adjMatrix = matrix_new(nVertexMax, nVertexMax);
        if(newGraph->adjMatrix != NULL){
            newGraph->nVertex = 0;
            newGraph->nVertexMax = nVertexMax;
        }else{
            free(newGraph);
            newGraph = NULL;
        }
    }
    return newGraph;
}

void graph_free(graph** ptr_g){
    matrix_free(&((*ptr_g)->adjMatrix));
    (*ptr_g)->nVertex = 0;
    (*ptr_g)->nVertexMax = 0;
    free(*ptr_g);
    *ptr_g = NULL;
}

int graph_addVertex(graph* g, int nNewVertex){
    int done = 0;
    if((g->nVertex + nNewVertex) > g->nVertexMax){
        matrix* new_adjMatrix = matrix_new((g->nVertex + nNewVertex)*2, (g->nVertex + nNewVertex)*2);
        if(new_adjMatrix != NULL){ 
            matrix_copy(g->adjMatrix, new_adjMatrix);
            matrix_free(&(g->adjMatrix));
            g->adjMatrix = new_adjMatrix;
            g->nVertex = g->nVertex + nNewVertex;
            g->nVertexMax = g->nVertex*2;
            done = 1;  
        }
    }else{
        g->nVertex = g->nVertex + nNewVertex;
        done = 1;
    }
    return done;
}

void graph_removeVertex(graph* g, int vertexToRemove){
    //Move destination columns
    for(int vertexOrigin = 0; vertexOrigin < g->nVertex; vertexOrigin++){
        for(int vertexDestination = vertexToRemove; vertexDestination < (g->nVertex - 1); vertexDestination++){
            graph_copyAdj(g, vertexOrigin, vertexDestination + 1,
                          g, vertexOrigin, vertexDestination);
        }
        digraph_setAdj(g, vertexOrigin, g->nVertex - 1, 0);
    }
    
    //Move origin rows
    for(int vertexDestination = 0; vertexDestination < g->nVertex; vertexDestination++){
        for(int vertexOrigin = vertexToRemove; vertexOrigin < (g->nVertex - 1); vertexOrigin++){
            graph_copyAdj(g, vertexOrigin + 1, vertexDestination,
                          g, vertexOrigin,     vertexDestination);
        }
        digraph_setAdj(g, g->nVertex - 1, vertexDestination, 0);
    }
}

int digraph_setAdj(graph* g, int vertexOrigin, int vertexDestination, int value){
    int done = 0;
    if(max(vertexOrigin, vertexDestination) < g->nVertex){
        matrix_set(g->adjMatrix, vertexDestination, vertexOrigin, value);
        done = 1;
    }
    return done;
}

int graph_setAdj(graph* g, int vertexOrigin, int vertexDestination, int value){
    int done = 0;
    if(max(vertexOrigin, vertexDestination) < g->nVertex){
        matrix_set(g->adjMatrix, vertexDestination, vertexOrigin, value);
        matrix_set(g->adjMatrix, vertexOrigin, vertexDestination, value);
        done = 1;
    }
    return done;
}

int graph_getAdj(graph* g, int vertexOrigin, int vertexDestination){
    return matrix_get(g->adjMatrix, vertexDestination, vertexOrigin);
}

void graph_copyAdj(graph* gFrom, int vertexOriginFrom, int vertexDestinationFrom,
                   graph* gTo,   int vertexOriginTo,   int vertexDestinationTo){
    int pathFrom = graph_getAdj(gFrom, vertexOriginFrom, vertexDestinationFrom);
    digraph_setAdj(gTo, vertexOriginTo, vertexDestinationTo, pathFrom);
}

void graph_printAdj(graph* graphToPrint){
    matrix_print(graphToPrint->adjMatrix, print_int);
}

list* graph_getAdjList(graph* g, int vertexOrigin){
    list* adjList = list_new();
    for(int vertexDestination = 0; vertexDestination < g->nVertex; vertexDestination++){
        int weight = graph_getAdj(g, vertexOrigin, vertexDestination);
        if(weight != 0){
            vertex newVertex;
            newVertex.vertexDestination = vertexDestination;
            newVertex.pathWeight = weight;
            list_append(adjList, newVertex); //add at the end
        }
    }
    list_cursorFirst(adjList);
    return adjList;
}

void graph_printAdjList(list* adjList){
    list_cursorFirst(adjList);
    while(list_cursorOnEOL(adjList) == 0){
        printf("%d ", list_cursorSeek(adjList).vertexDestination);
        list_cursorNext(adjList);
    }
    printf("\n");
}

void graph_printLevels(graph* g, int vertexOrigin){
    const int VISITED = 1;
    const int NOT_VISITED = 0;

    vector* visited = vector_new(g->nVertex);
    vector_set(visited, vertexOrigin, VISITED);
    queue* nextVertex = queue_new(100);
    queue_enqueue(nextVertex, vertexOrigin);
    while(!queue_isEmpty(nextVertex)){
        int currentVertex = queue_dequeue(nextVertex);
        list* adjList = graph_getAdjList(g, currentVertex);
        list_cursorFirst(adjList);
        while(list_cursorOnEOL(adjList) == 0){
            int vertexDestination = list_cursorSeek(adjList).vertexDestination;
            if(vector_seek(visited, vertexDestination) == NOT_VISITED){
                vector_set(visited, vertexDestination, VISITED);
                queue_enqueue(nextVertex, vertexDestination);
            }
            list_cursorNext(adjList);
        }
        printf("%d ", currentVertex);
    }
    printf("\n");
}

void graph_printDepth(graph* g, int vertexOrigin){
    vector* visited = vector_new(g->nVertex);
    vector_set(visited, vertexOrigin, 1);
    _printDepth(g, vertexOrigin, visited);
    vector_free(&visited);
}
void _printDepth(graph* g, int currentVertex, vector* visited){
    list* adjList = graph_getAdjList(g, currentVertex);
    list_cursorFirst(adjList);
    while(list_cursorOnEOL(adjList) == 0){
        int destinationVertex = list_cursorSeek(adjList).vertexDestination;
        if(vector_seek(visited, destinationVertex) == 0){
            vector_set(visited, destinationVertex, 1);
            _printDepth(g, destinationVertex, visited);
        }
        list_cursorNext(adjList);
    }
    list_free(adjList);
    printf("%d ", currentVertex);
}


int graph_degreeExit(graph* g, int vertex){
    list* adjList = graph_getAdjList(g, vertex);
    int degree = list_size(adjList);
    list_free(adjList);
    return degree;
}