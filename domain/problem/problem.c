#include "problem.h"
#include <stdlib.h>

Problem *problem_data_read(char *file) {
    Problem *P = malloc(sizeof(Problem));

    FILE *F = fopen(file, "r");

    int size;
    fscanf (F, "%d\n", size);

    P->graph = graph_construct();
    P->graph->size = size;
    
    int n_city;
    float distance;
    for (int i=0; i<size; i++) {
        P->graph->metropolis[i] = node_construct();
    }
    while (fscanf (F, "%d %f", n_city, distance) == 2) {
        
    }
}


void problem_data_destroy(Problem *P);
