#include "graphs.h"

Graph *graph_construct() {
    Graph *G = malloc(sizeof(Graph));
    G->metropolis = heap_construct();

    

    return G;
}