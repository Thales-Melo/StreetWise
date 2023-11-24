#include "path.h"
#include "../../utils/utils.h"
#include <stdlib.h>
#include <stdio.h>
#include "../parent/parent.h"

Path *path_construct() {
    Path *path = (Path*)malloc(sizeof(Path));
    path->route = list_construct();
    path->distance = 0;
    path->start_city = START_CITY;
    return path;
}


void path_destroy(Path *path) {
    list_destroy(path->route, free);
    free(path);
}


void path_print(Path *path) {
    list_print(path->route, print_int);
    printf ("%.2f\n", path->distance);
}


void path_add(Path *path, int id) {
    int *id_ptr = malloc(sizeof(int));
    if (id_ptr == NULL) {
        return;
    }

    *id_ptr = id;

    list_push_front(path->route, id_ptr);
}


Vector *path_vector_construct(Problem *P, Vector *parents) {
    Vector *paths = vector_construct();

    for (int i = 1; i < P->graph->size; i++) {
        Path *path = path_construct();
        Parent *par = (Parent *)vector_get(parents, i);
        path->distance = par->cost;

        while (par->id != 0) {
            path_add(path, par->id);
            par = (Parent *)vector_get(parents, par->parent);
        }

        path_add(path, START_CITY);

        vector_push_back(paths, path);
    }

    return paths;
}