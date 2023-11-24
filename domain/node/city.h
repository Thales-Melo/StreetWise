#ifndef _CITY_H_
#define _CITY_H_


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


#endif