#ifndef _CITY_H_
#define _CITY_H_

#include "../../stdData/heap/heap.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../stdData/vector/vector.h"

typedef struct{
    Vector *routes;
    int n_neighbors;
    float distance_to_start;
    int id;
} City;


City *city_construct();

void city_connect(City *N_1, City *N_2, float distance);

void city_destroy(City *city);

void city_print(data_type N, void (*print_fn)(data_type));

void city_disconnect_closest(City *N_1);

City *city_get_neighbor(City *N, int city_num);

int city_get_id(City *N);

float city_get_distance(City *N_1, int city_num);

int city_get_neighboors_size(City *N);

#endif