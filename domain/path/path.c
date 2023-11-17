#include "path.h"
#include "../../utils/utils.h"
#include <stdlib.h>
#include <stdio.h>

Path *path_construct() {
    Path *path = malloc(sizeof(Path));
    path->route = list_construct();
    path->distance = 0;
    path->start_city = START_CITY;
    return path;
}

void path_destroy(Path *path) {
    list_destroy(path->route, NULL);
    free(path);
}

void path_print(Path *path) {
    list_print(path->route, print_int);
    printf ("%.2f\n", path->distance);
}


