#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "../graphs/graphs.h"


typedef struct {
    Graph *graph;
} Problem;


Problem *problem_data_read(char *file);

void problem_data_destroy(Problem *P);


#endif