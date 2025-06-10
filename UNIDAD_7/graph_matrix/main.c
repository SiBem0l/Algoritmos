#include "graph.h"

int main(){
    graph* g = graph_create(3);
    graph_addVertex(g, 1);
    graph_addVertex(g, 10);
    graph_free(&g);
    return 0;
}
