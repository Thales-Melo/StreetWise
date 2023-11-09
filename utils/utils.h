#ifndef _UTILS_H_
#define _UTILS_H_

#define MENU_OPCAO_INVALIDA ( (opcao<1) || (opcao>12) )
#define LETRA_MAIUSCULA (*letra>=65 && *letra<=90)
#define LETRA_MINUSCULA (*letra>=97 && *letra<=122)
#define APROVADO 1
#define REPROVADO 0
#define DONT_SHOW_NUMBER_OF_THE_LINE 0
#define SHOW_NUMBER_OF_THE_LINE 1

typedef struct prof_reps {
  int count_reps;
  char professor_name[30];
}Prof_Reps;

typedef struct sub_summary {
  char *subject_name;
  char subject_code[10];
  char professor_name[30];
  float percent;
  int approvs;
  int num_regists;
  float grade_mean;
}Sub_summary;

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

int stu_rep_cmp(data_type A, data_type B);

int prof_rep_cmp(data_type A, data_type B);

void professor_rep_print(data_type data);

int subject_summary_cmp (data_type A, data_type B);

void subject_summary_print (data_type data);

Sub_summary *subject_summary_construct (char *subject_name, char *subject_code, char *professor_name, float percent, int approvs, int num_regists, float grade_mean);

void subject_summary_destroy (data_type data);

#endif