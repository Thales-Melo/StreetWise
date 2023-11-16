#ifndef _UTILS_H_
#define _UTILS_H_

#define TRUE 1
#define FALSE 0

typedef void* data_type;

void print_int(data_type data);

void print_float(void* data);

void print_string_topics(data_type data);

void viraMaiuscula (char *letra);

char *stringMaiuscula (char *str);

void printNegrito(const char* str);

void printVermelho(const char *str);

void printAmarelo(const char *str);

void limpaEntrada();

void freeString(data_type str);

int namecmp(data_type str_A, data_type str_B);

void criaPasta(char *nomePasta);

int naoLetra (char letra);

void freeArray(char **lista, int tam);

int intcmp(data_type A, data_type B);

int floatcmp(data_type A, data_type B);

#endif