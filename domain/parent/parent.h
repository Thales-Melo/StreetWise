#ifndef _PARENT_H_
#define _PARENT_H_

#include <stdio.h>

typedef struct {
    int parent;
    int id;
    double cost;
} Parent;

Parent *parent_construct(int parent, int id, double cost);

void parent_print(Parent *par);

void parent_destroy(Parent *par);

#endif