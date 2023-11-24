#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "../node/city.h"
#include "../route/route.h"
#include "../path/path.h"
#include "../parent/parent.h"
#include "../../stdData/heap/heap.h"


Vector *dijkstra_solve(Problem *P) {

    Vector *paths = vector_construct();
    bool *Visited = (bool*)calloc(P->graph->size, sizeof(bool));
    Heap *NotVisited = heap_construct();
    Vector *parents = vector_construct();

    for (int i=0; i<P->graph->size; i++) {
        vector_push_back(parents, NULL);
    }

    P->graph->metropolis[0]->distance_to_start = 0;

    Parent *origin = parent_construct(0, 0, 0);
    heap_push(NotVisited, origin, 0);
    
    int parent_id = 0;

    while (!heap_empty(NotVisited)) {
        HeapNode *HN = (HeapNode*)heap_pop(NotVisited, floatcmp);
        Parent *par = (Parent*)getHeapNodeData(HN);
        City *C = P->graph->metropolis[par->id];
        
        if (Visited[C->id] == FALSE) {
            Visited[C->id] = TRUE;
            parent_id = par->parent;
            vector_set(parents, C->id, parent_construct(parent_id, C->id, C->distance_to_start));
        }

        for (int i=0; i<C->n_neighbors; i++) {
            Route *neighboor = (Route*)vector_get(C->routes, i);
            if (neighboor == NULL) {
                continue;
            }
                if (neighboor->city->distance_to_start == 0) {
                    neighboor->city->distance_to_start = C->distance_to_start + neighboor->distance;
                }
                else if (neighboor->city->distance_to_start > C->distance_to_start + neighboor->distance) {
                    neighboor->city->distance_to_start = C->distance_to_start + neighboor->distance;
                }
                else {
                    continue;
                }

                heap_push(NotVisited, parent_construct(C->id, neighboor->city->id, C->distance_to_start + neighboor->distance), neighboor->city->distance_to_start);
        }

        heapNode_destroy(HN, parent_destroy);

    }


    for (int i=1; i<P->graph->size; i++) {
        Path *path = path_construct();
        Parent *par = (Parent*)vector_get(parents, i);
        path->distance = par->cost;
    
        while (par->id != 0) {
            path_add(path, par->id);
            par = (Parent*)vector_get(parents, par->parent);
        }

        path_add(path, START_CITY);

        vector_push_back(paths, path);

    }

    free(Visited);
    vector_destroy(parents, parent_destroy);
    heap_destroy(NotVisited, parent_destroy);

    return paths;
}