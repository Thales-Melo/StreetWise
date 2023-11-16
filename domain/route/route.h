#ifndef _ROUTE_H_
#define _ROUTE_H_

#include "../node/node.h"

typedef struct {
    Node *city;
    int city_num;
    float distance;
} Route;


Route *route_create(Node *city, int city_num, float distance);

void route_destroy(Route *r);

#endif