#include "city.h"
#include "../route/route.h"
#include "../../utils/utils.h"

City *city_construct () {
    City *C = (City*)malloc(sizeof(City));
    C->routes = vector_construct();
    C->distance_to_start = 0;
    C->n_neighbors = 0;
    C->id = 0;
    return C;
}

void city_connect(City *C_1, City *C_2, float distance) {
    Route *R = route_create(C_2, C_2->id, distance);
    // heap_push(C_1->routes, R, distance);
    vector_push_back(C_1->routes, R);
    C_1->n_neighbors++;
}

void city_destroy(City *city) {
    // printf ("CHEGOU AQUI - city\n");
    vector_destroy(city->routes, route_destroy);
    free(city);
}

void city_print(data_type N, void (*print_fn)(data_type)) {
    City *c = (City*)N;
    vector_print(c->routes, print_fn);
}

// void city_disconnect_closest(City *C_1) {
//     // Route *R = heap_pop(C_1->routes, floatcmp);
//     route_print(R);
//     route_destroy(R);
//     C_1->n_neighbors--;
// }


// City *city_get_neighbor(City *N, int city_num) {
//     for (int i=0; i<N->n_neighbors; i++) {
//         HeapNode *HN = (HeapNode*)heap_get(N->routes, i);
//         Route *R = (Route*)getHeapNodeData(HN);
//         if (R->city_num == city_num) {
//             return R->city;
//         }
//     }

//     return NULL;
// }

int city_get_id(City *N) {
    return N->id;
}


// float city_get_distance(City *N_1, int city_num) {
//     for (int i=0; i<N_1->n_neighbors; i++) {
//         HeapNode *HN = (HeapNode*)heap_get(N_1->routes, i);
//         Route *R = (Route*)getHeapNodeData(HN);
//         if (R->city_num == city_num) {
//             return R->distance;
//         }
//     }

//     return -1;
// }


int city_get_neighboors_size(City *N) {
    return N->n_neighbors;
}
