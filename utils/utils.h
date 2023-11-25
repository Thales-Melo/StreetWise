#ifndef _UTILS_H_
#define _UTILS_H_


#include <stdio.h>


#define TRUE 1
#define FALSE 0
#define STD_FILENAME_SIZE 100
typedef void* data_type;

/**
 * @brief Prints an integer
 * 
 * @param data
 * Pointer to the integer to be printed
*/
void print_int(data_type data);

/**
 * @brief Prints a string as bold
 * 
 * @param str
 * Pointer to the string to be printed
*/
void printNegrito(const char* str);

/**
 * @brief Prints a string as red
 * 
 * @param str
 * Pointer to the string to be printed
*/
void printVermelho(const char *str);

/**
 * @brief Prints a string as yellow
 * 
 * @param str
 * Pointer to the string to be printed
*/
void printAmarelo(const char *str);

/**
 * @brief Clears the input buffer
*/
void limpaEntrada();

/**
 * @brief Frees a string
 * 
 * @param str
 * Pointer to the string to be freed
*/
void freeString(data_type str);

/**
 * @brief Compares two strings
 * 
 * @param str_A
 * Pointer to the first string
 * @param str_B
 * Pointer to the second string
 * 
 * @return int
 * Returns 0 if the strings are equal
 * Returns 1 if the first string is greater than the second
 * Returns -1 if the first string is smaller than the second
*/
int namecmp(data_type str_A, data_type str_B);

/**
 * @brief Creates a folder
 * 
 * @param nomePasta
 * Pointer to the name of the folder to be created
*/
void criaPasta(char *nomePasta);

/**
 * @brief Checks if a character is not a letter
 * 
 * @param letra
 * The character to be checked
 * 
 * @return int
 * Returns 1 if the character is not a letter
 * Returns 0 if the character is a letter
*/
int naoLetra (char letra);

/**
 * @brief Frees a string array
 * 
 * @param lista
 * Pointer to the string array to be freed
 * @param tam
 * The size of the string array
*/
void freeArray(char **lista, int tam);

/**
 * @brief Compares two integers
 * 
 * @param A
 * Pointer to the first integer
 * @param B
 * Pointer to the second integer
 * 
 * @return int
 * Returns 0 if the integers are equal
 * Returns 1 if the first integer is greater than the second
 * Returns -1 if the first integer is smaller than the second
*/
int intcmp(data_type A, data_type B);

/**
 * @brief Compares two floats
 * 
 * @param A
 * Pointer to the first float
 * @param B
 * Pointer to the second float
 * 
 * @return int
 * Returns 0 if the floats are equal
 * Returns 1 if the first float is greater than the second
 * Returns -1 if the first float is smaller than the second
*/
int floatcmp(data_type A, data_type B);

/**
 * @brief Check if a file is valid
 * 
 * @param F
 * Pointer to the file to be checked
 * @param file_name
 * Pointer to the name of the file to be checked
 * 
 * @return int
 * Returns TRUE if the file is invalid
 * Returns FALSE if the file is valid
*/
int invalid_file(FILE *F, char *file_name);


#endif