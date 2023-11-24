#ifndef _PATH_H_
#define _PATH_H_

#include "../../stdData/DLL/list/list.h"

#define START_CITY 0

typedef struct {
    List *route;
    // int *route;
    float distance;
    int start_city;
    // int size;
    // int capacity;
} Path;

Path *path_construct();

void path_destroy(Path *path);

void path_print(Path *path);

void path_add(Path *path, int id);

void path_reverse(Path *path);

#endif