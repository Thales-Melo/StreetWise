#include "problem.h"
#include <stdlib.h>
#include "../../utils/utils.h"
#include "../route/route.h"

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
        // printf("%d %.0f ", n_city, distance);
        P->graph->metropolis[count]->id = count;
        city_connect(P->graph->metropolis[count], P->graph->metropolis[n_city], n_city, distance);
        if (getc(F) == '\n') {
            // printf ("count: %d\n", count);
            count++;
        }
        if (count == size) {
            break;
        }
    }

    // printf ("count: %d\n", count);
    
    // printf ("\n\n_________________\n\n");

    // for (int i=0; i<size; i++) {
        // printf ("CITY %d\n", i);
        // city_print(P->graph->metropolis[i], route_print);
        // printf ("\n\n_________________\n\n");
    // }

    // debug
    // city_disconnect_closest(P->graph->metropolis[5]);

    // printf ("\n\n_________________\n\n");
    // city_print(P->graph->metropolis[5], route_print);
    // printf ("\n\n_________________\n\n");

    fclose(F);

    return P;
}


void problem_data_destroy(Problem *P) {
    graph_destroy(P->graph);
    free(P);
}
