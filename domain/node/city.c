#include "city.h"
#include "../route/route.h"
#include "../../utils/utils.h"

City *city_construct () {
    City *C = (City*)malloc(sizeof(City));
    C->routes = heap_construct();
    C->distance_to_start = 0;
    return C;
}

void city_connect(City *C_1, City *C_2, int city_num, float distance) {
    Route *R = route_create(C_2, city_num, distance);
    heap_push(C_1->routes, R, distance);
}

void city_destroy(City *city) {
    heap_destroy(city->routes, route_destroy);
    free(city);
}

void city_print(data_type N, void (*print_fn)(data_type)) {
    City *c = (City*)N;
    heap_print(c->routes, print_fn);
}

void city_disconnect_closest(City *C_1) {
    Route *R = heap_pop(C_1->routes, floatcmp);
    route_print(R);
    route_destroy(R);
}

