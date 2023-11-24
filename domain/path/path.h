#ifndef _PATH_H_
#define _PATH_H_

#include "../../stdData/DLL/list/list.h"
#include "../problem/problem.h"
#include "../../stdData/vector/vector.h"

#define START_NODE 0


typedef struct {
    // Route is a Double Linked List because it is easier to add elements in any order
    // Also, if the user wants to access the last element
    // it is easier to do it with a DLL because it has a pointer to the last element
    // And if, in the future, there is a new node in the graph, the best path can change,
    // so its gonna be easier to change the path
    List *route;
    float distance;
} Path;


/**
 * @brief Construct a new Path struct
 * 
 * @return Path* 
 * Pointer to the new Path struct
 */
Path *path_construct();

/**
 * @brief Destroys a Path struct
 * 
 * @param path 
 * Pointer to the Path struct to be destroyed
 */
void path_destroy(Path *path);

/**
 * @brief Prints a Path struct
 * 
 * @param path 
 * Pointer to the Path struct to be printed
 */
void path_print(Path *path);

/**
 * @brief Adds a node to the path
 * 
 * @param path 
 * Pointer to the Path struct
 * @param id 
 * Id of the node to be added
 */
void path_add(Path *path, int id);

/**
 * @brief Constructs a vector of paths
 * 
 * @param P 
 * Pointer to the problem 
 * @param parents 
 * Pointer to the vector of parents
 * 
 * @return Vector*
 * Pointer to the vector of paths
 */
Vector *path_vector_construct(Problem *P, Vector *parents);

#endif