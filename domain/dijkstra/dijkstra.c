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

Vector *dijkstra_solve(Problem *P) {

    // bool *Visitados = (bool*)calloc(P->graph->size, sizeof(bool));
    // Heap *NaoVisitados = heap_construct();

    // heap_push(NaoVisitados, P->graph->metropolis[0], 0);

    
    
    return NULL;
}