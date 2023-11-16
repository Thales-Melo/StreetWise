#include "route.h"

Route *route_create(Node *city, int city_num, float distance) {
    Route *R = malloc(sizeof(Route));
    
    R->city = city;
    R->city_num = city_num;
    R->distance = distance;

    return R;
}

void route_destroy(Route *R) {
    free(R);
}

