#include "node.h"
#include "../route/route.h"

Node *node_construct () {
    Node *N = (Node*)malloc(sizeof(Node));
    N->routes = heap_construct();
    
    return N;
}

void node_connect(Node *N_1, Node *N_2, int city_num, float distance, int (*cmp_func)(data_type, data_type)) {
    Route *R = route_create(N_2, city_num, distance);
    // printf ("city: %d, distance: %.0f\n", R->city_num, R->distance);
    heap_push(N_1->routes, R, &distance, cmp_func, route_print);
    // printf ("\n\n_________________\n\n");
    // heap_print(N_1->routes, route_print);
    // printf ("\n\n_________________\n\n");
}

void node_destroy(Node *node) {
    heap_destroy(node->routes, route_destroy);
    free(node);
}

void node_print(data_type N, void (*print_fn)(data_type)) {
    Node *n = (Node*)N;
    heap_print(n->routes, print_fn);
}

void node_disconnect(Node *node, Node *other);

int node_is_connected(Node *node, Node *other);

int node_get_weight(Node *node, Node *other);

