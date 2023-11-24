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

Heap *heap_construct() {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    
    heap->nodes = vector_construct();
    heap->size = 0;
    heap->capacity = HEAP_INITIAL_CAPACITY;

    return heap;
}

#include "../../domain/route/route.h"
void heap_push(Heap *heap, data_type data, double priority) {
    HeapNode *HN = (HeapNode*)malloc(sizeof(HeapNode));

    HN->data = data;
    HN->priority = priority;
    // printf ("priority: %.0f\n\n", *(float*)HN->priority);
    vector_push_back(heap->nodes, HN);
    // TO PRINTANDO AQUI (DEBUG)
    // vector_print(heap->nodes, route_print);
    heap->size++;
    heap_heapify_up(heap, heap->size-1);
    if (heap->size == heap->capacity) {
        heap->capacity *= HEAP_GROWTH_RATE;
    }
}

bool heap_empty(Heap *heap) {
    if (heap->size == 0) {
        return 1;
    }
    else {
        return 0;
    }
} // O(1)

data_type heap_max(Heap *heap) {
    return vector_get(heap->nodes, 0);
} // O(1)

double heap_max_priority(Heap *heap) {
    HeapNode *aux = (HeapNode*)vector_get(heap->nodes, 0);
    return aux->priority;
} // O(1)

data_type heap_pop(Heap *heap, int(*cmp_func)(data_type, data_type)) {
    if (heap->size == 0) {
        return NULL;
    }

    HeapNode *super_grandparent = vector_get(heap->nodes, 0);
    
    vector_swap(heap->nodes, 0, heap->size-1);
    vector_pop_back(heap->nodes);

    heap->size--;

    heap_heapify_down(heap, 0, cmp_func);
   
    return super_grandparent;
}


// Nesta implementação, em vez de usar vector_pop_front, eu substituí o nó raiz pelo último nó e, em seguida, reduzi o tamanho do heap. Em seguida, chamei heap_heapify_down para manter a propriedade de heap. Essa abordagem é eficiente e mantém a complexidade de tempo em O(log N). Certifique-se de ajustar qualquer tratamento de erro ou valor padrão conforme necessário.


void heap_destroy(Heap *heap, void(*free_func)(data_type)) {
    vector_destroy(heap->nodes, free_func);
    free(heap);
}

void heap_heapify_up(Heap *heap, int idx) {
    int parent = (idx - 1)/2;
    HeapNode *HN_1 = vector_get(heap->nodes, parent);
    HeapNode *HN_2 = vector_get(heap->nodes, idx);

    // printf ("parent: %d, idx: %d\n", parent, idx);
    // printf ("cmp_func = %d\n", cmp_func(HN_2->priority, HN_1->priority));

    if ((parent >= 0) && (HN_2->priority - HN_1->priority < 0)) {
        swap_nodes(heap, idx, parent);
        // printf ("ENTROU NO HEAP_HEAPIFY_UP\n");
        heap_heapify_up(heap, parent);
    }
}


void heap_heapify_down(Heap *heap, int idx, int(*cmp_func)(data_type, data_type)) {
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
        heap_heapify_down(heap, largest, cmp_func);
    }
}


void swap_nodes(Heap *heap, int idx1, int idx2) {
    HeapNode *aux = vector_get(heap->nodes, idx1);
    vector_set(heap->nodes, idx1, vector_get(heap->nodes, idx2));
    vector_set(heap->nodes, idx2, aux);
}

void heap_print(Heap *heap, void(*print_func)(data_type)) {
    vector_print(heap->nodes, print_func);
}

void heapNode_print(data_type data) {
    HeapNode *aux = (HeapNode*)data;

    printf("%s - %.2f\n", (char*)aux->data, aux->priority);
}

void heapNode_destroy(data_type data, void(*free_func)(data_type)) {
    HeapNode *aux = (HeapNode*)data;
    if (free_func != NULL) {
        free_func(aux->data);
    }
    free(aux);
}

data_type getHeapNodeData(HeapNode *HN) {
    return HN->data;
}

double getHeapNodePriority(HeapNode *HN) {
    return HN->priority;
}

data_type heap_get(Heap *heap, int idx) {
    return vector_get(heap->nodes, idx);
}