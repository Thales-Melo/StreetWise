#include "route.h"

Route *route_create(Node *city, int city_num, float distance) {
    Route *R = malloc(sizeof(Route));
    
    R->city = city;
    R->city_num = city_num;
    R->distance = distance;
    
    return R;
}

void route_destroy(data_type R) {
    Route *r = (Route*)R;
    free(r->city);
    free(r);
}

void route_print(data_type R) {
    Route *r = (Route*)R;
    printf ("city: %d, distance: %.1f\n", r->city_num, r->distance);
}