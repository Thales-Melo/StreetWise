#ifndef _NODE_H_
#define _NODE_H_

#include "../../stdData/heap/heap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    Heap *routes;
} Node;


Node *node_construct();

void node_connect(Node *N_1, Node *N_2, int city_num, float distance);

void node_destroy(Node *node);

void node_print(data_type N, void (*print_fn)(data_type));

void node_disconnect_closest(Node *N_1);

int node_is_connected(Node *N_1, Node *N_2);

int node_get_weight(Node *N_1, Node *N_2);


#endif