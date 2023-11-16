#include "problem.h"
#include <stdlib.h>

Problem *problem_data_read(char *file) {
    Problem *P = malloc(sizeof(Problem));

    FILE *F = fopen(file, "r");

    int size;
    fscanf (F, "%d\n", size);

    P->graph = graph_construct();
    P->graph->size = size;
    
}


void problem_data_destroy(Problem *P);
