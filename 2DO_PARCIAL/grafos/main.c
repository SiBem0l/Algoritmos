#include "graph.h"

void _vertexPerDegree(graph* g, int currentVertex, vector* visited, vector* nPerDegree){
    int degree = graph_degreeExit(g, currentVertex);
    vector_set(nPerDegree, degree, vector_seek(nPerDegree, degree) + 1);

    list* adj = graph_getAdjList(g, currentVertex);
    list_cursorFirst(adj);
    while(list_cursorOnEOL(adj) == 0){
        int destinationVertex = list_cursorSeek(adj).vertexDestination;
        if(vector_seek(visited, destinationVertex) == 0){ //not visited
            vector_set(visited, destinationVertex, 1);
            _vertexPerDegree(g, destinationVertex, visited, nPerDegree);
        }
        list_cursorNext(adj);
    }
    list_free(adj);
}
void vertexPerDegree(graph* g, int vertexOrigin, vector* nPerDegree){
    vector* visited = vector_new(g->nVertex);
    vector_set(visited, vertexOrigin, 1);
    _vertexPerDegree(g, vertexOrigin, visited, nPerDegree);
    vector_free(&visited);
}

int main()
{   const int N_VERTEX = 6;
    const int A = 0;
    const int B = 1;
    const int C = 2;
    const int D = 3;
    const int E = 4;
    const int F = 5;

    graph* testGraph = graph_create(N_VERTEX);
    graph_addVertex(testGraph, N_VERTEX);

    digraph_setAdj(testGraph, A, B, CONNECTED);

    digraph_setAdj(testGraph, B, A, CONNECTED);
    digraph_setAdj(testGraph, B, C, CONNECTED);

    digraph_setAdj(testGraph, C, A, CONNECTED);
    digraph_setAdj(testGraph, C, E, CONNECTED);
    digraph_setAdj(testGraph, C, D, CONNECTED);

    digraph_setAdj(testGraph, D, E, CONNECTED);
    digraph_setAdj(testGraph, D, B, CONNECTED);

    digraph_setAdj(testGraph, E, A, CONNECTED);

    digraph_setAdj(testGraph, F, A, CONNECTED);
    digraph_setAdj(testGraph, F, E, CONNECTED);
    

    int a = graph_degreeExit(testGraph, A);
    int b = graph_degreeExit(testGraph, B);
    int c = graph_degreeExit(testGraph, C);
    int d = graph_degreeExit(testGraph, D);
    int e = graph_degreeExit(testGraph, E);
    int f = graph_degreeExit(testGraph, F);

    vector* nPerDegree = vector_new(N_VERTEX);
    vertexPerDegree(testGraph, A, nPerDegree);

    vector_free(&nPerDegree);
    return 0;
}
