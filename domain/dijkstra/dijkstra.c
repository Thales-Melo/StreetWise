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
#include "../parent/parent.h"


Vector *dijkstra_solve(Problem *P) {

    Vector *paths = vector_construct();
    // Path *paths = path_construct(P->graph->size);
    
    bool *Visited = (bool*)calloc(P->graph->size, sizeof(bool));
    Heap *NotVisited = heap_construct();
    Vector *parents = vector_construct();
    // inicializar o vetor parents com 0
    for (int i=0; i<P->graph->size; i++) {
        vector_push_back(parents, parent_construct(0, 0, 0));
    }

    P->graph->metropolis[0]->distance_to_start = 0;
    // Inicializa o vetor de não visitados com a origem
    Parent *origin = parent_construct(0, 0, 0);
    heap_push(NotVisited, origin, 0);
    int parent_id = 0;

    // vector_push_back(path)
    // path_add(paths, 0);

    while (!heap_empty(NotVisited)) {
        HeapNode *HN = (HeapNode*)heap_pop(NotVisited, floatcmp);
        Parent *par = (Parent*)getHeapNodeData(HN);
        printf ("\n\npar->id: %d\n", par->id);
        printf ("par->cost: %lf\n", par->cost);
        printf ("par->parent: %d\n\n", par->parent);
        City *C = P->graph->metropolis[par->id];
        printf ("C->id: %d\n", C->id);
        printf ("C->distance_to_start: %lf\n", C->distance_to_start);
        printf ("C->n_neighbors: %d\n\n", C->n_neighbors);
        

        if (Visited[C->id] == FALSE) {
            Visited[C->id] = TRUE;
            parent_id = par->parent;
            // vector_push_back(parents, parent_construct(parent_id, C->id, C->distance_to_start));
            vector_set(parents, C->id, parent_construct(parent_id, C->id, C->distance_to_start));
            printf ("parent_id: %d\n", parent_id);
            printf ("C->id: %d\n", C->id);
            printf ("C->distance_to_start: %lf\n\n", C->distance_to_start);
            // Recupear o heap_max
        
        }

        for (int i=0; i<C->n_neighbors; i++) {
            HeapNode *aux = (HeapNode*)heap_pop(C->routes, floatcmp);
            printf ("C->size = %d\n", C->n_neighbors);
            if (aux == NULL) {
                printf ("aux == NULL\n");
                continue;
            }
            Route *neighboor = (Route*)getHeapNodeData(aux);
            // if (Visited[neighboor->city->id] == FALSE) {
                // neighboor->city->distance_to_start += neighboor->distance;
                // float original_distance = neighboor->city->distance_to_start;
                if (neighboor->city->distance_to_start == 0) {
                    neighboor->city->distance_to_start = C->distance_to_start + neighboor->distance;
                }
                else if (neighboor->city->distance_to_start > C->distance_to_start + neighboor->distance) {
                    neighboor->city->distance_to_start = C->distance_to_start + neighboor->distance;
                }
                else {
                    continue;
                }
                // neighboor->city->distance_to_start = C->distance_to_start + neighboor->distance;
                printf("pai: %d\n", C->id);
                printf ("neighboor->city->id: %d\n", neighboor->city->id);
                printf ("pai->distance_to_start: %lf\n", C->distance_to_start);
                printf ("neighboor->city->distance_to_start: %lf\n", neighboor->city->distance_to_start);
                printf ("neighboor->distance: %lf\n", neighboor->distance);

                heap_push(NotVisited, parent_construct(C->id, neighboor->city->id, C->distance_to_start + neighboor->distance), neighboor->city->distance_to_start);
                // neighboor->city->distance_to_start = original_distance;
            // }
        }


    }


    for (int i=0; i<P->graph->size; i++) {
        printf("Parent: %d, id: %d, cost: %.2lf\n", ((Parent*)vector_get(parents, i))->parent, ((Parent*)vector_get(parents, i))->id, ((Parent*)vector_get(parents, i))->cost);
    }

    // construir o paths agora com a menor rota completa
    // para cada cidade, pegar o parent no vetor de parents e ir adicionando no path

    for (int i=1; i<P->graph->size; i++) {
        Path *path = path_construct();
        Parent *par = (Parent*)vector_get(parents, i);
        path->distance = par->cost;
    
        while (par->id != 0) {
            printf ("par->id: %d\n", par->id);
            printf ("par->parent: %d\n", par->parent);
            path_add(path, par->id);
            par = (Parent*)vector_get(parents, par->parent);
            printf ("||||||||||||");
            printf ("par->id: %d\n", par->id);
            printf ("par->parent: %d\n", par->parent);
            printf ("\n\n");
        }

        int start_city = 0;
        path_add(path, start_city);
        // vector_reverse(path->route);
        // path_print(path);
        vector_push_back(paths, path);


        printf ("\n\n|||||||||||||||\n\n");
    }

    return paths;
}