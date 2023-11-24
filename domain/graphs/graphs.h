/*
   AQUI EU USO O TERMO "METROPOLIS" PARA ME REFERIR AO GRAFO PROPRIAMENTE DITO
   JÁ QUE CADA NÓ ESTÁ SENDO CHAMADO DE "CITY", FIZ ISSO PARA FACILITAR A COMPREENSÃO
*/

#ifndef _GRAPHS_H_
#define _GRAPHS_H_


#include "../node/city.h"


typedef struct {
    int size;
    City **metropolis;
} Graph;

/**
 * @brief Construct a new Graph
 * 
 * @param size
 * The number of cities (nodes) in the graph
 * 
 * @return Graph* 
 * Pointer to the graph to be constructed
 */
Graph *graph_construct (int size);

/**
 * @brief Destroy the Graph
 * 
 * @param graph 
 * Pointer to the graph to be destroyed
 */
void graph_destroy (Graph *graph);


#endif
