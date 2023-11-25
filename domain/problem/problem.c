#include "problem.h"
#include <stdlib.h>
#include "../../utils/utils.h"
#include "../route/route.h"
#include <stdio.h>
#include "../../view/view.h"

Problem *problem_data_read(char *file) {
    FILE *F = fopen(file, "r");
    
    // Verificar entradas que possivelmente quebram o programa
    if (invalid_file(F, file)) {
        return NULL;
    }

    Problem *prob = malloc(sizeof(Problem));

    int size;
    fscanf (F, "%d\n", &size);

    prob->graph = graph_construct(size);
    prob->graph->size = size;
    
    int n_city;
    float distance;
    int count = 0;

    while (fscanf(F, "%d %f", &n_city, &distance) == 2) {
        prob->graph->metropolis[count]->id = count;
        city_connect(prob->graph->metropolis[count], prob->graph->metropolis[n_city], distance);
        if (getc(F) == '\n') {
            count++;
        }
        if (count == size) {
            break;
        }
    }
    
    fclose(F);

    return prob;
}


void problem_data_destroy(Problem *prob) {
    graph_destroy(prob->graph);
    free(prob);
}
