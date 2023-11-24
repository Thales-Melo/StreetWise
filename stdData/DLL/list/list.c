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


void list_push_back(List *l, data_type data) {
    if (l->size == 0) {
        l->head = node_construct(data, NULL, NULL);
        l->last = l->head;
        l->size++;
        return;
    }
    else {
        Node *aux = node_construct(data, l->last, NULL);
        l->last->next = aux;
        l->last = aux;
        l->size++;
    }
}


void list_print(List *l, void (*print_fn)(data_type)) {
    Node *aux = l->head;
    while (aux != NULL) {
        node_print(aux, print_fn);
        if (aux->next != NULL) {
            printf (" -> ");
        }
        aux = aux->next;
    }
    printf (": ");
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
