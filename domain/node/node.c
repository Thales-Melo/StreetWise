#include "node.h"
#include "../route/route.h"

Node *node_construct () {
    Node *N = malloc(sizeof(Node));
    N->connections = heap_construct();

    return N;
}

void node_connect(Node *N_1, Node *N_2, int city_num, float distance, int (*cmp_func)(data_type, data_type)) {
    int city_num;
    float distance;

    route *R = route_create(N_2, city_num, distance);
    
    heap_push(N_1->routes, R, distance, cmp_func);
}

void node_destroy(Node *node) {
    heap_destroy(node->connections, NULL);
    free(node);
}

void node_disconnect(Node *node, Node *other);

int node_is_connected(Node *node, Node *other);

int node_get_weight(Node *node, Node *other);

