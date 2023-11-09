#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

#define VECTOR_FILE "vector_data.txt"
#define EXISTE 1
#define NAO_EXISTE 0

typedef void* data_type;

typedef struct {
    data_type *data;
    int size;
    int allocated;
} Vector;

// Aloca espaço para um elemento do tipo vector e inicializa os seus atributos.
Vector *vector_construct(); 

// Libera o espaço reservado para o vector.
void vector_destroy(Vector *v, void(*free_func)(data_type)); 

// Adiciona o item dado ao final do vector e aumenta o tamanho. Aumenta a capacidade alocada se necessário.
void vector_push_back(Vector *v, data_type val); 

// Retorna o número de elementos atualmente no vector.
int vector_size(Vector *v); 

// Retorna o i-ésimo elemento do vector.
data_type vector_get(Vector *v, int i); 

// Atualiza o i-ésimo elemento do vector  para que ele passe a ter o valor val. 
void vector_set(Vector *v, int i, data_type val); 

// Retorna o índice da primeira ocorrência do item no Vector ou -1 se o elemento não for encontrado.
int vector_find(Vector *v, data_type val, int(*cmp_func)(data_type, data_type)); 

///////////////////////////////////////////////////////////////
// LAB-2
////////////////////////////////////////////////////////////// 


// Remove o i-ésimo elemento do vetor.
data_type vector_remove(Vector *v, int i); 

// Remove o primeiro elemento
data_type vector_pop_front(Vector *v); 

// Remove o ultimo elemento
data_type vector_pop_back(Vector *v); 

// Insere o elemento na i-esima posicao
void vector_insert(Vector *v, int i, data_type val); 

// Troca os elementos das posições i e j (i vira j e j vira i)
void vector_swap(Vector *v, int i, int j); 

// Ordena o vetor in-place (sem criar um novo vetor)
void vector_sort(Vector *v);

// // Retorna o indice de val usando busca binaria. Retorna -1 se nao encontrado.
int vector_binary_search(Vector *v, data_type val);

// // Inverte o vetor in-place (sem criar um novo vetor)
void vector_reverse(Vector *v); 

// // Cria uma cópia do vector e dos valores de seus atributos.
// Vector *vector_copy(Vector *v); 

// // Remove todos os elementos de v
// void vector_clear(Vector *v);

///////////////////////////////////////////////////////////////
// EXTRA
////////////////////////////////////////////////////////////// 

// void vector_save(Vector *v, char *file);

// Vector *vector_load(char *file);

// int vector_data_is_stored (char *file);

void vector_print(Vector *v, void(*print_func)(data_type));

#endif