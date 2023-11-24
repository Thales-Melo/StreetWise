#include <stdio.h>
#include <stdlib.h>
#include "view/view.h"
#include "stdData/heap/heap.h"
#include "stdData/vector/vector.h"
#include "domain/problem/problem.h"
#include "domain/dijkstra/dijkstra.h"
#include "domain/path/path.h"

void print_and_destroy_paths(Vector *paths)
{   
    for (int i = 0; i < vector_size(paths); i++)
    {
        Path *path = (Path*)vector_get(paths, i);
        path_print(path);
        path_destroy(path);
    }
    vector_destroy(paths, NULL);
}


int main() {
    // logo();
    Problem *problem_data = problem_data_read("file/inputs/input.txt");
    Vector *paths = dijkstra_solve(problem_data);

    print_and_destroy_paths(paths);
    
    problem_data_destroy(problem_data);

    return 0;
}

//  entry format:
// 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./main > file/outputs/reality/output.txt
//  diff format:
//  diff -w file/outputs/expectation/output.txt file/outputs/reality/output.txt 