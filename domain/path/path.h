#ifndef _PATH_H_
#define _PATH_H_

#include "../../stdData/DLL/list/list.h"
#include "../problem/problem.h"
#include "../../stdData/vector/vector.h"

#define START_CITY 0


typedef struct {
    List *route;
    float distance;
    int start_city;
} Path;


Path *path_construct();

void path_destroy(Path *path);

void path_print(Path *path);

void path_add(Path *path, int id);

Vector *path_vector_construct(Problem *P, Vector *parents);

#endif