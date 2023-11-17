#ifndef _PATH_H_
#define _PATH_H_

#include "../../stdData/DLL/list/list.h"

#define START_CITY 0

typedef struct {
    List *route;
    float distance;
    int start_city;
} Path;

Path *path_construct();

void path_destroy(Path *path);

void path_print(Path *path);

#endif