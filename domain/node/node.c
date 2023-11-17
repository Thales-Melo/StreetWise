#include "node.h"
#include "../route/route.h"
#include "../../utils/utils.h"

Node *node_construct () {
    Node *N = (Node*)malloc(sizeof(Node));
    N->routes = heap_construct();
    
    return N;
}

void node_connect(Node *N_1, Node *N_2, int city_num, float distance) {
    Route *R = route_create(N_2, city_num, distance);
    heap_push(N_1->routes, R, distance);
}

void node_destroy(Node *node) {
    heap_destroy(node->routes, route_destroy);
    free(node);
}

void node_print(data_type N, void (*print_fn)(data_type)) {
    Node *n = (Node*)N;
    heap_print(n->routes, print_fn);
}

void node_disconnect_closest(Node *N_1) {
    Route *R = heap_pop(N_1->routes, floatcmp);
    route_print(R);
    route_destroy(R);
}

int node_is_connected(Node *N_1, Node *N_2);

int node_get_weight(Node *N_1, Node *N_2);

