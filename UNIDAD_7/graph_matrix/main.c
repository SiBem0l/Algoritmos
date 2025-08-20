#include "graph.h"

int main(){
    const int N_VERTEX = 6;
    const int A = 0;
    const int B = 1;
    const int C = 2;
    const int D = 3;
    const int E = 4;
    const int F = 5;

    graph* testGraph = graph_create(N_VERTEX);
    graph_addVertex(testGraph, N_VERTEX);

    graph_setAdj(testGraph, A, B, CONNECTED);
    graph_setAdj(testGraph, A, C, CONNECTED);
    graph_setAdj(testGraph, B, E, CONNECTED);
    graph_setAdj(testGraph, B, D, CONNECTED);
    graph_setAdj(testGraph, C, E, CONNECTED);
    graph_setAdj(testGraph, D, E, CONNECTED);
    graph_setAdj(testGraph, D, F, CONNECTED);
    graph_setAdj(testGraph, E, F, CONNECTED);

    graph_printAdj(testGraph);
    graph_printLevels(testGraph, A);
    graph_printDepth(testGraph, A);

    graph_free(&testGraph);
    return 0;
}
