#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void print_int(data_type data) {
  printf("%d", *((int*)data));
}

void print_float(void* data) {
  printf("%.2f", *((float*)data));
}

void print_string_topics(data_type data) {
  printf ("• %s", (char*)data);
}

void viraMaiuscula (char *letra) {
  //Se a letra for minúscula, transforma.
  if (LETRA_MINUSCULA) {
    *letra-=32;
  }

  //Se a letra for maiúscula, mantém.
}

char *stringMaiuscula (char *str) {
  int size = strlen(str);

  for (int i=0; i<size; i++) {
    if (str[i]>='a' && str[i]<='z') {
      str[i]=str[i]-32;
    }
  }
  return str;
}

void printNegrito(const char* str) {
  printf("\033[1m%s\033[0m", str);
}

void printVermelho(const char *str) {
  printf("\033[1;31m%s\033[0m", str);
}

void printAmarelo(const char *str) {
  printf("\033[1;33m%s\033[0m", str);
}

void limpaEntrada() {
  scanf("%*c");
}

void freeString(data_type str) {
  char* STR = (char*) str;

  if (STR!=NULL) {
    free(STR);
    STR=NULL;
  }
}

int namecmp(data_type str_A, data_type str_B) {
  char* a = (char*) str_A;
  char* b = (char*) str_B;

  return strcmp(a, b);
}

void criaPasta(char *nomePasta) {
  char *conferePasta=(char*)malloc(sizeof(char)*30);
  sprintf(conferePasta, "test -d %s", nomePasta);
  if (system(conferePasta) != 0) {
      char *criaPasta=(char*)malloc(sizeof(char)*30);
      sprintf(criaPasta, "mkdir %s", nomePasta);
      system(criaPasta);
      free(criaPasta);
  }
  free(conferePasta);
}

int naoLetra (char letra) {
  if (letra<'A' || letra>'z' || (letra>'Z' && letra<'a')) {
    return 1;
  }
  return 0;
}

void freeArray(char **lista, int tam) {
    for (int i=0; i<tam; i++) {
        freeString(lista[i]);
    }
    free(lista);
}

int intcmp(data_type A, data_type B) {
  int a = *(int*)A;
  int b = *(int*)B;
  return a-b;
}

int stu_rep_cmp(data_type A, data_type B) {
  char *a = (char*)A;
  char *b = (char*)B;

  return strcmp(a, b);
}

int prof_rep_cmp(data_type A, data_type B) {
  Prof_Reps *a = (Prof_Reps*)A;
  Prof_Reps *b = (Prof_Reps*)B;

  return b->count_reps - a->count_reps;
}

void professor_rep_print(data_type data) {
  Prof_Reps *prof = (Prof_Reps*)data;
  printf ("• %s: %d\n", prof->professor_name, prof->count_reps);
  printf ("\n");
}

int subject_summary_cmp (data_type A, data_type B) {
  Sub_summary *a = (Sub_summary*)A;
  Sub_summary *b = (Sub_summary*)B;
  // Caso a porcentagem seja igual, ordena por número de matrículas
  // Porque se a disciplina tinha mais alunos porém com o mesmo número de aprovações, então o aproveitamento é menor
  if (a->percent*100 == b->percent*100) {
    return a->num_regists - b->num_regists;
  }

  // Se a porcentagem for diferente, ordena por porcentagem
  return (b->percent*100 - a->percent*100);
}

void subject_summary_print (data_type data) {
  Sub_summary *SS = (Sub_summary*)data;
  printf ("• Nome: %s\n", SS->subject_name);
  printf ("• Código: %s\n", SS->subject_code);
  printf ("• Professor: %s\n", SS->professor_name);
  printf ("• Aprovações: %d\n", SS->approvs);
  printf ("• Nº Matrículas: %d\n", SS->num_regists);
  printf ("• Aproveitamento: %.2f%%\n", SS->percent);
  printf ("• Nota média: %.2f\n\n", SS->grade_mean);
}

Sub_summary *subject_summary_construct (char *subject_name, char *subject_code, char *professor_name, float percent, int approvs, int num_regists, float grade_mean) {
  Sub_summary *SS = (Sub_summary*)malloc(sizeof(Sub_summary));
  SS->subject_name = (char*)malloc(sizeof(char)*(strlen(subject_name)+1));
  strcpy(SS->subject_name, subject_name);
  strcpy(SS->subject_code, subject_code);
  strcpy(SS->professor_name, professor_name);
  SS->percent = percent;
  SS->approvs = approvs;
  SS->num_regists = num_regists;
  SS->grade_mean = grade_mean;

  return SS;
}

void subject_summary_destroy (data_type data) {
  Sub_summary *SS = (Sub_summary*)data;
  free(SS->subject_name);

  if (SS != NULL) {
    free(SS);
    SS = NULL;
  }
}