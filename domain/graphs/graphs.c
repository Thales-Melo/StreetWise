#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>


Graph *graph_construct(int size) {
    Graph *G = malloc(sizeof(Graph));

    G->metropolis = (City**)malloc(sizeof(City*)*size);
    for (int i=0; i<size; i++) {
        G->metropolis[i] = city_construct();
    }
    
    return G;
}


void graph_destroy(Graph *graph) {
    for (int i=0; i<graph->size; i++) {
        city_destroy(graph->metropolis[i]);
    }
    free(graph->metropolis);
    free(graph);
}