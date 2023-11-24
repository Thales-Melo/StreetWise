#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "../node/city.h"
#include "../route/route.h"
#include "../path/path.h"
#include "../parent/parent.h"

/**
 * @brief Helper function to perform the actual Dijkstra's algorithm.
 * It is used in the main function "dijkstra_solve" and exists only in the .c file.
 * 
 * @param P
 * The problem to be solved
 * @param parents
 * The array of parents
 * @param Visited
 * Array of booleans to mark visited nodes
 * @param NotVisited
 * Heap of unvisited nodes
*/
void dijkstra_algorithm(Problem *P, Vector *parents, bool *Visited, Heap *NotVisited) {
    P->graph->metropolis[0]->distance_to_start = 0;
    //Inicializa o heap com o nó de origem
    Parent *origin = parent_construct(0, 0, 0);
    heap_push(NotVisited, origin, 0);

    int parent_id = 0;

    // Enquanto houver nós não visitados, o algoritmo continua
    while (!heap_empty(NotVisited)) {
        Parent *par = (Parent *)heap_pop(NotVisited);
        City *C = P->graph->metropolis[par->id];

        // Só entra no if se o nó não foi visitado
        // Se entrar, ele é marcado como visitado e adicionado ao vetor de pais
        if (!Visited[C->id]) {
            Visited[C->id] = TRUE;
            parent_id = par->parent;
            vector_set(parents, C->id, parent_construct(parent_id, C->id, C->distance_to_start));
        }

        // Loop para percorrer os vizinhos do nó atual, adicioná-los no
        // heap e atualizar a distância deles quando a distância atual
        // for menor que a encontrada em alguma iteração anterior
        for (int i = 0; i < C->n_neighbors; i++) {
            Route *neighbor = (Route *)vector_get(C->routes, i);

            int new_distance = C->distance_to_start + neighbor->distance;

            if (neighbor->city->distance_to_start == 0 || neighbor->city->distance_to_start > new_distance) {
                neighbor->city->distance_to_start = new_distance;
                heap_push(NotVisited, parent_construct(C->id, neighbor->city->id, new_distance), neighbor->city->distance_to_start);
            }
        }

        free(par);
    }
}


Vector *dijkstra_solve(Problem *P) {
    bool *Visited = (bool *)calloc(P->graph->size, sizeof(bool));
    Heap *NotVisited = heap_construct();
    Vector *parents = parent_vector_initialize(P->graph->size);

    // Executa o algoritmo de Dijkstra
    dijkstra_algorithm(P, parents, Visited, NotVisited);

    // Cria o vetor de caminhos a partir do vetor de pais
    Vector *paths = path_vector_construct(P, parents);

    free(Visited);
    vector_destroy(parents, parent_destroy);
    heap_destroy(NotVisited, parent_destroy);

    return paths;
}