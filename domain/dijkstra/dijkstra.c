#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "../node/city.h"
#include "../route/route.h"
#include "../path/path.h"
#include "../parent/parent.h"


void dijkstra_algorithm(Problem *P, Vector *parents, bool *Visited, Heap *NotVisited) {
    P->graph->metropolis[0]->distance_to_start = 0;

    Parent *origin = parent_construct(0, 0, 0);
    heap_push(NotVisited, origin, 0);

    int parent_id = 0;

    while (!heap_empty(NotVisited)) {
        Parent *par = (Parent *)heap_pop(NotVisited);
        City *C = P->graph->metropolis[par->id];

        if (!Visited[C->id]) {
            Visited[C->id] = TRUE;
            parent_id = par->parent;
            vector_set(parents, C->id, parent_construct(parent_id, C->id, C->distance_to_start));
        }

        for (int i = 0; i < C->n_neighbors; i++) {
            Route *neighbor = (Route *)vector_get(C->routes, i);
            if (neighbor == NULL) {
                continue;
            }

            int new_distance = C->distance_to_start + neighbor->distance;

            if (neighbor->city->distance_to_start == 0 || neighbor->city->distance_to_start > new_distance) {
                neighbor->city->distance_to_start = new_distance;
                heap_push(NotVisited, parent_construct(C->id, neighbor->city->id, new_distance), neighbor->city->distance_to_start);
            }
        }

        free(par);
    }
}


Vector *dijkstra_solve(Problem *P) {
    bool *Visited = (bool *)calloc(P->graph->size, sizeof(bool));
    Heap *NotVisited = heap_construct();
    Vector *parents = parent_vector_initialize(P->graph->size);

    dijkstra_algorithm(P, parents, Visited, NotVisited);
    Vector *paths = path_vector_construct(P, parents);

    free(Visited);
    vector_destroy(parents, parent_destroy);
    heap_destroy(NotVisited, parent_destroy);

    return paths;
}