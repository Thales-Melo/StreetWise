#include "city.h"
#include "../route/route.h"
#include "../../utils/utils.h"
#include <stdlib.h>
#include <stdio.h>


City *city_construct () {
    City *C = (City*)malloc(sizeof(City));

    C->routes = vector_construct();
    C->distance_to_start = 0;
    C->n_neighbors = 0;
    C->id = 0;

    return C;
}


void city_connect(City *city_1, City *city_2, float distance) {
    Route *R = route_create(city_2, city_2->id, distance);
    
    vector_push_back(city_1->routes, R);
    city_1->n_neighbors++;
}


void city_destroy(City *city) {
    vector_destroy(city->routes, route_destroy);
    free(city);
}


void city_print(data_type city, void (*print_fn)(data_type)) {
    City *c = (City*)city;
    vector_print(c->routes, print_fn);
}
