#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include "../graphs/graphs.h"


typedef struct {
    // Aqui na struct problem, eu tenho um grafo porque o problema é um grafo
    // Mas se o problema fosse X, eu teria um X aqui
    // Uma vez que "Problema" é um conceito abstrato, logo, pode ser qualquer coisa
    Graph *graph;
} Problem;


/**
 * @brief Reads the problem data from a file
 * 
 * @param file 
 * The file to be read
 * 
 * @return Problem* 
 * The problem data
 
*/
Problem *problem_data_read(char *file);

/**
 * @brief Destroy the problem data
 * 
 * @param prob
 * The problem data to be destroyed
*/
void problem_data_destroy(Problem *prob);


#endif