#include "graphs.h"

Graph *graph_construct(int size) {
    Graph *G = malloc(sizeof(Graph));
    G->metropolis = (Node**)malloc(sizeof(Node*)*size);
    for (int i=0; i<size; i++) {
        G->metropolis[i] = node_construct();
    }

    
    return G;
}

void graph_destroy(Graph *graph) {
    for (int i=0; i<graph->size; i++) {
        node_destroy(graph->metropolis[i]);
    }
    free(graph->metropolis);
    free(graph);
}