#ifndef _GRAPHS_H_
#define _GRAPHS_H_

#include <stdio.h>
#include "../node/node.h"

typedef struct {
    int size;
    Node **metropolis;
} Graph;

Graph *graph_construct (int size);

void graph_destroy (Graph *graph);

#endif
