#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "../../stdData/vector/vector.h"
#include "../problem/problem.h"
#include "../../stdData/heap/heap.h"

/**
 * @brief Solves the problem using Dijkstra's algorithm
 * 
 * @param problem 
 * The problem to be solved
 * 
 * @return Vector*
 * The vector of parents
 */
Vector *dijkstra_solve(Problem *problem);

#endif