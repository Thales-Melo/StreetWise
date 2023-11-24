#include "route.h"
#include "../../stdData/heap/heap.h"
#include <stdlib.h>
#include <stdio.h>


Route *route_create(City *city, int city_num, float distance) {
    Route *R = malloc(sizeof(Route));
    
    R->city = city;
    R->city_num = city_num;
    R->distance = distance;

    return R;
}


void route_destroy(data_type R) {
    Route *r = (Route*)R;
    if (r != NULL) {
        free(r);
    }
}
