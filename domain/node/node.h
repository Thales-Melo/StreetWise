#ifndef _NODE_H_
#define _NODE_H_

#include "../../stdData/heap/heap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    Heap *routes;
} Node;


Node *node_construct();

void node_connect(Node *N_1, Node *N_2, int city_num, float distance, int (*cmp_func)(data_type, data_type));

void node_destroy(Node *node);

void node_disconnect(Node *node, Node *other);

int node_is_connected(Node *node, Node *other);

int node_get_weight(Node *node, Node *other);


#endif