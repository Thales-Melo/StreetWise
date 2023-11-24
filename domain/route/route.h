#ifndef _ROUTE_H_
#define _ROUTE_H_

#include "../node/city.h"


typedef struct {
    City *city;
    int city_num;
    float distance;
} Route;


/**
 * @brief Creates a new Route struct
 * 
 * @param city
 * Pointer to the city of destination
 * @param city_num
 * The id of the city of destination
 * @param distance
 * The cost of the edge
*/
Route *route_create(City *city, int city_num, float distance);

/**
 * @brief Destroys a Route struct
 * 
 * @param R
 * Pointer to the Route struct to be destroyed
*/
void route_destroy(data_type R);


#endif