#ifndef _PARENT_H_
#define _PARENT_H_


#include "../../stdData/vector/vector.h"


typedef struct {
    int parent; // id do pai
    int id; // id do nó
    float cost; // custo do nó até o nó inicial
} Parent;

/**
 * @brief Constructs a parent struct
 * 
 * @param parent
 * The id from the parent of the node
 * @param id
 * The id of the node
 * @param cost
 * The cost of the node until the start node
 * 
 * @return Parent*
 * Pointer to a parent struct
*/
Parent *parent_construct(int parent, int id, float cost);

/**
 * @brief Initializes a vector of parents
 * 
 * @param size
 * The size of the vector
 * 
 * @return Vector*
 * Pointer to the vector of parents
*/
Vector *parent_vector_initialize(int size);

/**
 * @brief Prints a parent struct
 * 
 * @param par
 * Pointer to the parent struct to be printed
*/
void parent_print(Parent *par);

/**
 * @brief Destroys a parent struct
 * 
 * @param data
 * Pointer to the parent struct to be destroyed
*/
void parent_destroy(void *data);


#endif