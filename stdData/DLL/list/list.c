#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List *list_construct() {
    List *l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->last = NULL;
    l->size = 0;

    return l;
}


int list_size(List *l) {
    return l->size;
}


void list_push_front(List *l, data_type data) {
    if (l->size == 0) {
        l->head = node_construct(data, NULL, NULL);
        l->last = l->head;
        l->size++;
        return;
    }
    else {
        Node *aux = node_construct(data, NULL, l->head);
        l->head->prev = aux;
        l->head = aux;
        l->size++;
    }
}


void list_push_back(List *l, data_type data, void (*print_fn)(data_type)) {
    printf("\ndata: ");
    print_fn(data);
    printf ("\nl->value:");
    if (l->size == 0) {
        l->head = node_construct(data, NULL, NULL);
        l->last = l->head;
        l->size++;
        print_fn(l->head->value);
        printf("\n");
        return;
    }
    else {
        Node *aux = node_construct(data, l->last, NULL);
        l->last->next = aux;
        l->last = aux;
        l->size++;
        print_fn(l->last->value);
        printf("\n");
    }
}

void list_print(List *l, void (*print_fn)(data_type)) {
    Node *aux = l->head;
    // printf ("list->size: %d\n", l->size);
    // printf ("[");
    while (aux != NULL) {
        node_print(aux, print_fn);
        // print_fn(aux->value);
        if (aux->next != NULL) {
            printf (" -> ");
        }
        aux = aux->next;
    }
    printf (": ");
}

void list_print_reverse(List *l, void (*print_fn)(data_type)) {
    Node *aux = l->last;
    printf ("[");
    while (aux != NULL) {
        node_print(aux, print_fn);

        if (aux->prev != NULL) {
            printf (", ");
        }
        aux = aux->prev;
    }
    printf ("]");
}

data_type list_get(List *l, int i) {
    if (i == 0) {
        return l->head->value;
    }
    else {
        Node *aux = l->head;
        for (int j=0; j<i; j++) {
            printf ("a");
            aux = aux->next;
        }
        return aux->value;
    }
}

data_type list_pop_front(List *l, void (*free_func)(data_type)) {
    Node *aux = l->head;
    data_type value = aux->value;
    l->head = aux->next;
    node_destroy(aux, free_func);

    l->size--;

    return value;
}


data_type list_pop_back(List *l, void (*free_func)(data_type)) {
    Node *aux = l->last;
    data_type value = aux->value;
    l->last = aux->prev;
    node_destroy(aux, free_func);

    l->size--;

    return value;
}

// List *list_reverse(List *l) {
//     List *new_list = list_construct();
//     Node *aux = l->last;
//     while (aux != NULL) {
//         list_push_back(new_list, aux->value);
//         aux = aux->prev;
//     }

//     return new_list;
// }

// void list_clear(List *l);


// void list_remove(List *l, data_type val);


// void list_unique(List *l);


// void list_cat(List *l, List *m);


// void list_sort(List *l);


void list_destroy(List *l, void (*free_func)(data_type)) {
    Node *aux;

    for (int i=0; i<l->size; i++) {
        aux = l->head->next;
        node_destroy(l->head, free_func);
        l->head = aux;
    }

    l->size = 0;
    
    free(l);
}
