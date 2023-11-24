#include "parent.h"
#include <stdio.h>
#include <stdlib.h>


Parent *parent_construct(int parent, int id, float cost) {
    Parent *par = (Parent*)malloc(sizeof(Parent));
    par->parent = parent;
    par->id = id;
    par->cost = cost;
    return par;
}


Vector *parent_vector_initialize(int size) {
    Vector *parents = vector_construct();
    for (int i = 0; i < size; i++) {
        vector_push_back(parents, NULL);
    }
    return parents;
}


void parent_print(Parent *par) {
    printf("Parent: %d, id: %d, cost: %f\n", par->parent, par->id, par->cost);
}


void parent_destroy(void *data) {
    Parent *par = (Parent*)data;
    free(par);
}
