#ifndef _ROUTE_H_
#define _ROUTE_H_

#include "../node/city.h"

typedef struct {
    City *city;
    int city_num;
    float distance;
} Route;


Route *route_create(City *city, int city_num, float distance);

void route_destroy(data_type R);

void route_print(data_type R);

#endif