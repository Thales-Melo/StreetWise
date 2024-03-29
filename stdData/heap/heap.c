#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include "../vector/vector.h"


struct HeapNode {
    data_type data;
    double priority;
};

struct Heap {
    Vector *nodes;
    // Cada elemento do vector vai ser um HeapNode
    int size;
    int capacity;
};

////////////////////////////////////////////////
// Hidden functions from the user of the heap //
////////////////////////////////////////////////

// Returns the HeapNode's data
data_type getHeapNodeData(HeapNode *HN) {
    return HN->data;
}


// Returns the HeapNode's priority
double getHeapNodePriority(HeapNode *HN) {
    return HN->priority;
}


// Destroys a HeapNode
void heapNode_destroy(data_type data, void(*free_func)(data_type)) {
    HeapNode *aux = (HeapNode*)data;
    if (free_func != NULL) {
        free_func(aux->data);
    }
    free(aux);
}


// Prints a HeapNode
void heapNode_print(data_type data) {
    HeapNode *aux = (HeapNode*)data;

    printf("%s - %.2f\n", (char*)aux->data, aux->priority);
}


/**
 * @brief Swaps two nodes in the heap
 * 
 * @param heap
 * Pointer to the heap
 * @param idx1
 * The index of the first node
 * @param idx2
 * The index of the second node
*/
void swap_nodes(Heap *heap, int idx1, int idx2) {
    HeapNode *aux = vector_get(heap->nodes, idx1);
    vector_set(heap->nodes, idx1, vector_get(heap->nodes, idx2));
    vector_set(heap->nodes, idx2, aux);
}


/**
 * @brief Fixes the heap property by moving the newly inserted element to the correct position
 * 
 * @param heap
 * Pointer to the heap
 * @param idx
 * The index of the element to be manipulated
*/
void heap_heapify_up(Heap *heap, int idx) {
    int parent = (idx - 1)/2;
    HeapNode *HN_1 = vector_get(heap->nodes, parent);
    HeapNode *HN_2 = vector_get(heap->nodes, idx);

    if ((parent >= 0) && (HN_2->priority - HN_1->priority < 0)) {
        swap_nodes(heap, idx, parent);
        heap_heapify_up(heap, parent);
    }
}

/**
 * @brief Fixes the heap property by moving the smallest or largest element to the root and recursively fixing the heap property for the whole heap
 * 
 * @param heap
 * Pointer to the heap
 * @param idx
 * The index of the element to be manipulated
*/
void heap_heapify_down(Heap *heap, int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;

    if (left < heap->size) {
        HeapNode *HN_L = (HeapNode *)vector_get(heap->nodes, left);
        HeapNode *HN_LARG = (HeapNode *)vector_get(heap->nodes, largest);
        
        if (HN_L->priority - HN_LARG->priority < 0) {
            largest = left;
        }
    }
    
    if (right < heap->size) {
        HeapNode *HN_R = (HeapNode *)vector_get(heap->nodes, right);
        HeapNode *HN_LARG = (HeapNode *)vector_get(heap->nodes, largest);

        if (HN_R->priority - HN_LARG->priority < 0) {
            largest = right;
        }
    }

    if (largest != idx) {
        swap_nodes(heap, idx, largest);
        heap_heapify_down(heap, largest);
    }
}


/////////////////////////////////////////////
// FUNÇÕES QUE O USUÁRIO DO HEAP PODE USAR //
/////////////////////////////////////////////


Heap *heap_construct() {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    
    heap->nodes = vector_construct();
    heap->size = 0;
    heap->capacity = HEAP_INITIAL_CAPACITY;

    return heap;
}


void heap_destroy(Heap *heap, void(*free_func)(data_type)) {
    vector_destroy(heap->nodes, free_func);
    free(heap);
}


void heap_push(Heap *heap, data_type data, double priority) {
    HeapNode *HN = (HeapNode*)malloc(sizeof(HeapNode));

    HN->data = data;
    HN->priority = priority;

    vector_push_back(heap->nodes, HN);
    heap->size++;

    if (heap->size == heap->capacity) {
        heap->capacity *= HEAP_GROWTH_RATE;
    }
    
    heap_heapify_up(heap, heap->size-1);
    
}


data_type heap_pop(Heap *heap) {
    if (heap->size == 0) {
        return NULL;
    }

    HeapNode *super_grandparent = vector_get(heap->nodes, 0);
    
    vector_swap(heap->nodes, 0, heap->size-1);
    vector_pop_back(heap->nodes);

    heap->size--;

    heap_heapify_down(heap, 0);

    data_type aux = super_grandparent->data;

    free(super_grandparent);
    
    return aux;
}


void heap_print(Heap *heap, void(*print_func)(data_type)) {
    vector_print(heap->nodes, print_func);
}


data_type heap_get(Heap *heap, int idx) {
    return vector_get(heap->nodes, idx);
}


bool heap_empty(Heap *heap) {
    if (heap->size == 0) {
        return 1;
    }
    
    else {
        return 0;
    }
}


data_type heap_max(Heap *heap) {
    return vector_get(heap->nodes, 0);
}


double heap_max_priority(Heap *heap) {
    HeapNode *aux = (HeapNode*)vector_get(heap->nodes, 0);
    return aux->priority;
}




