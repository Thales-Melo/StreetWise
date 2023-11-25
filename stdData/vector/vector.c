#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define VECTOR_STD_SIZE 10
#define VECTOR_GROWTH_RATE 2


struct vector {
    data_type *data;
    int size;
    int allocated;
};


Vector *vector_construct() {
    Vector *v = (Vector*)malloc(sizeof(Vector));

    v->allocated = VECTOR_STD_SIZE;
    v->data = (data_type*)malloc(sizeof(data_type)*v->allocated);
    v->size = 0;

    return v;
}


void vector_destroy(Vector *v, void(*free_func)(data_type)) {
    if (free_func == NULL) {
        free(v->data);
        free(v);
        return;
    }
    for (int i=0; i<v->size; i++) {
        if (v->data[i] != NULL) {
            free_func(v->data[i]);
            v->data[i] = NULL;
        }
    }
    free(v->data);
    free(v);
}


void vector_push_back(Vector *v, data_type val) {
    if (v->size == v->allocated) {
        v->allocated *= VECTOR_GROWTH_RATE;
        v->data = (data_type*)realloc(v->data, sizeof(data_type)*v->allocated);
    }
    v->data[v->size] = val;
    v->size++;
}


int vector_size(Vector *v) {
    return v->size;
}


data_type vector_get(Vector *v, int i) {
    if ((i >= 0) && i < (v->size)) {
        return v->data[i];
    }
    else {
        printf ("vector_get: Invalid index\n");
        printf ("i = %d\n", i);
        exit(1);
    }
}


void vector_set(Vector *v, int i, data_type val) {
    if ((i >= 0) && i < (v->size)) {
        v->data[i] = val;
    }
    else {
        printf ("vector_set: Invalid index\n");
        printf ("i = %d\n", i);
        exit(1);
    }
}


int vector_find(Vector *v, data_type val, int(*cmp_func)(data_type, data_type)) {
    for (int i=0; i<v->size; i++) {
        if (cmp_func(v->data[i], val) == 0) {
            return i;
        }
    }

    return -1;
}


///////////////////////////////////////////////////////////////
// LAB-2
///////////////////////////////////////////////////////////////


data_type vector_remove(Vector *v, int i) {
    data_type item = v->data[i];

    for (int k=i; k<v->size-1; k++) {
        v->data[k] = v->data[k+1];
    }

    v->size--;
    
    return item;
}


data_type vector_pop_front(Vector *v) {
    data_type first = v->data[0];
    for (int i=0; i<v->size-1; i++) {
        v->data[i] = v->data[i+1];
    }

    vector_pop_back(v);
    if (first == NULL) {
        printf ("first == NULL\n");
        exit(1);
    }
    return first;
}


data_type vector_pop_back(Vector *v) {
    if (v->size == 0) {
        printf ("vector_pop_back: Vector is empty\n");
        return NULL;
    }
    data_type last = v->data[v->size-1];
    v->size--;

    if (last == NULL) {
        printf ("last == NULL\n");
        return NULL;
    }
    return last;
}


void vector_insert(Vector *v, int i, data_type val) {
    if (v->size == v->allocated) {
        v->allocated *= VECTOR_GROWTH_RATE;
        v->data = (data_type*)realloc(v->data, sizeof(data_type)*v->allocated);
    }

    v->size++;

    for (int k=v->size-1; k>i; k--) {
        v->data[k] = v->data[k-1];
    }

    v->data[i] = val;
}


void vector_swap(Vector *v, int i, int j) {
    data_type aux = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = aux;
}


void vector_sort (Vector *v) {
    for (int i=0; i<v->size; i++) {
        for (int j=i+1; j<v->size; j++) {
            if (v->data[j] < v->data[i]) {
                vector_swap(v, i, j);
            }
        }
    }
}


int vector_binary_search(Vector *v, data_type val) {
    int first = 0;
    int last = v->size-1;
    int mid;

    while (first <= last) {
        mid = (first + last) / 2;

        if (val < v->data[mid]) {
            last = mid - 1;
        }
        
        else if (val  > v->data[mid]) {
            first = mid + 1;
        }

        else {
            return mid;
        }
    }

    return -1;
}


void vector_reverse(Vector *v) {
    for (int i=0; i<v->size/2; i++) {
        vector_swap(v, i, v->size-1-i);
    }
}


void vector_print(Vector *v, void(*print_func)(data_type)) {
    for (int i=0; i<v->size; i++) {
        print_func(v->data[i]);
    }
}


///////////////////////////////////////////////////////////////
// EXTRA
///////////////////////////////////////////////////////////////