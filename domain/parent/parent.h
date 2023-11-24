#ifndef _PARENT_H_
#define _PARENT_H_


#include "../../stdData/vector/vector.h"


typedef struct {
    int parent;
    int id;
    float cost;
} Parent;


Parent *parent_construct(int parent, int id, float cost);

Vector *parent_vector_initialize(int size);

void parent_print(Parent *par);

void parent_destroy(void *data);


#endif