#include "path.h"
#include "../../utils/utils.h"
#include <stdlib.h>
#include <stdio.h>

#define ROUTE_LIST_STD_SIZE 10
#define ROUTE_LIST_GROWTH_RATE 2

Path *path_construct() {
    Path *path = (Path*)malloc(sizeof(Path));
    path->route = list_construct();
    // path->route = (int*)malloc(sizeof(int)*ROUTE_LIST_STD_SIZE);
    path->distance = 0;
    path->start_city = START_CITY;
    // path->size = 0;
    // path->capacity = ROUTE_LIST_STD_SIZE;
    return path;
}

void path_destroy(Path *path) {
    list_destroy(path->route, free);
    free(path);
}

void path_print(Path *path) {
    list_print(path->route, print_int);
    // for (int i=0; i<path->size; i++) {
    //     if (i != path->size-1){
    //         printf ("%d -> ", path->route[i]);
    //     }
    //     else{
    //         printf ("%d:", path->route[i]);
    //     }
    // }
    printf ("%.2f\n", path->distance);
}

// void path_list_print(Path *path) {
    
// }

void path_add(Path *path, int id) {
    int *id_ptr = malloc(sizeof(int));
    if (id_ptr == NULL) {
        // Tratar falha na alocação de memória, se necessário
        return;
    }

    *id_ptr = id;

    list_push_front(path->route, id_ptr);
}


void path_reverse(Path *path) {
    // path->route = list_reverse(path->route);
}
