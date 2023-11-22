// PSEUDOCÓDIGO

// Algoritmo Dijkstra(Grafo, Origem):
// 1. Crie um vector de valores booleanos chamado "Visitados" com tamanho igual ao número
// de nós. Inicialize os valores como falso e quando um nó for visitado, mude o valor para 1.
// 2. Crie uma fila de prioridade "NaoVisitados" com o nó origem e distância para a origem
// zero.
// 3. Crie um vector do tamanho do número de nós para armazenar o antecessor de cada no
// seu caminho mínimo (de onde ele veio) e o custo para o antecessor.
// 4. Enquanto houver vértices não visitados e a fila de prioridades não for vazia:
// 5. Escolha o nó não visitado U com a menor distância para a origem em "NaoVisitados" e
// o marque como visitado (adicione-o no conjunto "Visitados").
// 6. Para cada vizinho não visitado V de U:
// 7. Calcule a distância de V para a origem passando por U somando a distância de U para
// a origem e a distância entre U e V.
// 8. Adicione o par (V, distância) em "NaoVisitados". Se a distância do par
// 9. Retorne a estrutura com os caminhos mínimos.

#include "dijkstra.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../utils/utils.h"
#include "../node/city.h"
#include "../route/route.h"
#include "../path/path.h"


Vector *dijkstra_solve(Problem *P) {

    Vector *paths = vector_construct();
    // Path *paths = path_construct(P->graph->size);
    
    bool *Visited = (bool*)calloc(P->graph->size, sizeof(bool));
    Heap *NotVisited = heap_construct();

    P->graph->metropolis[0]->distance_to_start = 0;
    heap_push(NotVisited, P->graph->metropolis[0], 0);

    // vector_push_back(path)
    // path_add(paths, 0);

    while (!heap_empty(NotVisited)) {
        City *C = (City*)heap_pop(NotVisited, floatcmp);
        Visited[C->id] = TRUE;

        for (int i=0; i<C->n_neighbors; i++) {
            Route *neighboor = (Route*)heap_pop(C->routes, floatcmp);
            neighboor->city->distance_to_start += neighboor->distance;

            if (Visited[neighboor->city->id] == FALSE) {
                heap_push(NotVisited, neighboor->city, neighboor->city->distance_to_start);
            }
        }


    }


    
    return paths;
}