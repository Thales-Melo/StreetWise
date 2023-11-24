#include "problem.h"
#include <stdlib.h>
#include "../../utils/utils.h"
#include "../route/route.h"
#include <stdio.h>


Problem *problem_data_read(char *file) {
    Problem *P = malloc(sizeof(Problem));

    FILE *F = fopen(file, "r");

    int size;
    fscanf (F, "%d\n", &size);

    P->graph = graph_construct(size);
    P->graph->size = size;
    
    int n_city;
    float distance;
    int count = 0;

    while (fscanf(F, "%d %f", &n_city, &distance) == 2) {
        P->graph->metropolis[count]->id = count;
        city_connect(P->graph->metropolis[count], P->graph->metropolis[n_city], distance);
        if (getc(F) == '\n') {
            count++;
        }
        if (count == size) {
            break;
        }
    }
    fclose(F);

    return P;
}


void problem_data_destroy(Problem *P) {
    graph_destroy(P->graph);
    free(P);
}
