// ¿Cómo resolver operaciones básicas?
// Insertar arista
// Eliminar arista
// Insertar vértice
// Eliminar vértice
// Comprobar la existencia de una arista
// Verificar si un vértice es adyacente de otro
// Obtener la lista de vértices adyacentes
// Obtener el costo de recorrer una arista

#include <stdlib.h>
#include "graph.h"

//Crea un grafo de la catidad de vertices maximo pedida
graph* graph_create(int n_vertex_max){
    graph* new_graph = (graph*)malloc(sizeof(graph));
    if(new_graph != NULL){
        //creo la matriz y la lleno de 0
        new_graph->adj_matrix = matrix_new(n_vertex_max, n_vertex_max);
        if(new_graph->adj_matrix != NULL){
            new_graph->n_vertex = 0;
            new_graph->n_vertex_max = n_vertex_max;
        }else{
            free(new_graph);
            new_graph = NULL;
        }
    }
    return new_graph;
}

//Elimina un grafo y libera su memoria
void graph_free(graph** ptr_g){
    matrix_free(&((*ptr_g)->adj_matrix));
    (*ptr_g)->n_vertex = 0;
    (*ptr_g)->n_vertex_max = 0;
    free(*ptr_g);
    *ptr_g = NULL;
}

//Agrego n cantidad de vertices al grafo
int graph_addVertex(graph* g, int n_new_vertex){
    int done = 0;
    if((g->n_vertex + n_new_vertex) > g->n_vertex_max){
        matrix* new_adj_matrix = matrix_new((g->n_vertex + n_new_vertex)*2, (g->n_vertex + n_new_vertex)*2);
        if(new_adj_matrix != NULL){ 
            matrix_copy(g->adj_matrix, new_adj_matrix);
            matrix_free(&(g->adj_matrix));
            g->adj_matrix = new_adj_matrix;
            g->n_vertex = g->n_vertex + n_new_vertex;
            g->n_vertex_max = g->n_vertex*2;
            done = 1;  
        }
    }else{
        g->n_vertex = g->n_vertex + n_new_vertex;
        done = 1;
    }
    return done;
}

//Eliminar vertice pedido
void graph_removeVertex(graph* g, int vertex){

}

int graph_setAdy(graph* g, int orig, int dest, int value){

}
int graph_getAdy(graph* g, int orig, int dest){

}
void graph_copyAdy(graph* g_from, int orig_from, int dest_from, graph* g_to, int orig_to, int dest_to){
    
}




// Primitivas (ejemplos)
// Cantidad de vértices
// Cantidad de aristas por vértice
// Obtener valor vértice v
// Obtener peso arista (u,v)

