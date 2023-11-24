/*
    ALGUMAS FUNÇÕES QUE TRATAM DO HEAP EXISTEM SOMENTE NO ARQUVO .C 
    POIS O USUÁRIO NÃO DEVE TER ACESSO DIRETO A ELAS
    SOMENTE AS FUNÇÕES QUE ESTÃO NO ARQUIVO .H SÃO DE ACESSO PÚBLICO
*/

#ifndef _HEAP_H_
#define _HEAP_H_


typedef unsigned char bool;
typedef void* data_type;
typedef struct Heap Heap;
typedef struct HeapNode HeapNode;


#define HEAP_INITIAL_CAPACITY 10
#define HEAP_GROWTH_RATE 2


/**
 * @brief Creates a new Heap struct
 * 
 * @return Heap*
 * Pointer to the heap created
*/
Heap *heap_construct();

/**
 * @brief Destroys a Heap struct
 * 
 * @param heap
 * Pointer to the heap to be destroyed
 * @param free_func
 * Pointer to the function that frees the memory allocated for the values stored in the heap
*/
void heap_destroy(Heap *heap, void(*free_func)(data_type));

/**
 * @brief Pushes a new element to the heap
 * 
 * @param heap
 * Pointer to the heap of destination
 * @param data
 * The value to be stored in the heap
 * @param priority
 * The priority of the value
*/
void heap_push(Heap *heap, data_type data, double priority);

/**
 * @brief Pops the root of the heap
 * 
 * @param heap
 * Pointer to the heap
 * 
 * @return data_type
 * The value popped from the heap
*/
data_type heap_pop(Heap *heap);

/**
 * @brief Prints the heap using the vector_print function (so, the heap is printed linearly like a vector)
 * 
 * @param heap
 * Pointer to the heap
 * @param print_func
 * Pointer to the function that prints the values stored in the heap
*/
void heap_print(Heap *heap, void(*print_func)(data_type));

/**
 * @brief Returns the element of the heap at the given index
 * 
 * @param heap
 * Pointer to the heap
 * @param idx
 * The index of the element to be returned
 * 
 * @return data_type
 * The value stored in the heap at the given index
*/
data_type heap_get(Heap *heap, int idx);

/**
 * @brief Returns 1 if the heap is empty, 0 otherwise
 * 
 * @param heap
 * Pointer to the heap to be checked
 * 
 * @return bool
 * Bool is a typedef for unsigned char, so it can be used as a boolean
*/
bool heap_empty(Heap *heap);

/**
 * @brief Returns the root of the heap
 * 
 * @param heap
 * Pointer to the heap
 * 
 * @return data_type
 * The value stored in the root of the heap
*/
data_type heap_max(Heap *heap);

/**
 * @brief Returns the priority of the root of the heap
 * 
 * @param heap
 * Pointer to the heap
 * 
 * @return double
 * The priority of the root of the heap
*/
double heap_max_priority(Heap *heap);


#endif