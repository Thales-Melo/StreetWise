#include "route.h"
#include "../../stdData/heap/heap.h"

Route *route_create(City *city, int city_num, float distance) {
    Route *R = malloc(sizeof(Route));
    
    R->city = city;
    R->city_num = city_num;
    R->distance = distance;

    return R;
}

void route_destroy(data_type R) {
    Route *r = (Route*)R;
    // free(r->city);
    // printf ("CHEGOU AQUI - route\n");
    // exit(0);
    if (r != NULL) {
        free(r);
    }
}

// DESCOBRI O PROBLEMA... EU PRECISAVA DE UM HEAPNODE PRA PODER USAR O ROUTE EM CIMA DO HEAPNODE->DATA 
void route_print(data_type R) {
    HeapNode *h = (HeapNode*)R;
    Route *r = (Route*)getHeapNodeData(h);
    printf ("city: %d, distance: %.1f", r->city_num, r->distance);
    printf (" priority: %.1f\n", (double)getHeapNodePriority(h));
}
