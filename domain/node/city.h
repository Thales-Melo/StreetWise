/* 
   AQUI EU USO O TERMO "CITY" PARA ME REFERIR AOS NÓS DO GRAFO
   PORQUE JÁ EXISTE UM TIPO "NODE" NA LISTA DUPLAMENTE ENCADEADA QUE EU USEI
   ENTÃO, PARA EVITAR PROBLEMAS, EU USEI O TERMO "CITY" PARA ME REFERIR AOS NÓS DO GRAFO
   IMAGINE O GRAFO COMO UMA METRÓPOLE, ONDE CADA NÓ É UMA CIDADE
*/

#ifndef _CITY_H_
#define _CITY_H_


#include "../../stdData/vector/vector.h"


typedef struct{
    Vector *routes; // vector que contém as rotas para as cidades vizinhas
    int n_neighbors; // número de vizinhos
    float distance_to_start; // distância até a cidade inicial
    int id; // id da cidade
} City;


/**
 * @brief Construct a new City object
 * 
 * @return City*
*/
City *city_construct();

/**
 * @brief Connects two cities
 * 
 * @param C_1 
 * City 1 (the one that will have a route to city 2)
 * @param C_2
 * City 2 (the one that will be connected to city 1)
 * @param distance 
 * Distance between the two cities
*/
void city_connect(City *C_1, City *C_2, float distance);

/**
 * @brief Destroy the City struct
 * 
 * @param city 
 * Pointer to the city to be destroyed
*/
void city_destroy(City *city);

/**
 * @brief Prints a city
 * 
 * @param N 
 * Pointer to the city to be printed
 * @param print_fn 
 * Function pointer that prints the city
*/
void city_print(data_type N, void (*print_fn)(data_type));


#endif