#ifndef _HEAP_H_
#define _HEAP_H_

typedef unsigned char bool;
typedef void* data_type;
typedef struct Heap Heap;
typedef struct HeapNode HeapNode;

#define HEAP_INITIAL_CAPACITY 10
#define HEAP_GROWTH_RATE 2

Heap *heap_construct();

void heap_push(Heap *heap, data_type data, data_type priority, int(*cmp_func)(data_type, data_type), void(*print_fn)(data_type));

bool heap_empty(Heap *heap);

data_type heap_max(Heap *heap);

data_type heap_max_priority(Heap *heap);

data_type heap_pop(Heap *heap, int(*cmp_func)(data_type, data_type));

void heap_destroy(Heap *heap, void(*free_func)(data_type));

void heap_heapify_up(Heap *heap, int idx, int(*cmp_func)(data_type, data_type));

void heap_heapify_down(Heap *heap, int idx, int(*cmp_func)(data_type, data_type));

void swap_nodes(Heap *heap, int idx1, int idx2);

void heap_print(Heap *heap, void(*print_func)(data_type));

void heapNode_print(data_type data);

void heapNode_destroy(data_type data);

#endif