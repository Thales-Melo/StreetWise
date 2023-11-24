#ifndef _GRAPHS_H_
#define _GRAPHS_H_


#include "../node/city.h"


typedef struct {
    int size;
    City **metropolis;
} Graph;


Graph *graph_construct (int size);

void graph_destroy (Graph *graph);


#endif
