#ifndef _CITY_H_
#define _CITY_H_

#include "../../stdData/heap/heap.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    Heap *routes;
    float distance_to_start;
} City;


City *city_construct();

void city_connect(City *N_1, City *N_2, int city_num, float distance);

void city_destroy(City *city);

void city_print(data_type N, void (*print_fn)(data_type));

void city_disconnect_closest(City *N_1);

int city_is_connected(City *N_1, City *N_2);

int city_get_weight(City *N_1, City *N_2);


#endif