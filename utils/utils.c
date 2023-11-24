#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void print_int(data_type data) {
  int d = *(int*)data;
  printf("%d", d);
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

int floatcmp(data_type A, data_type B) {
  float a = *(float*)A;
  float b = *(float*)B;
  printf ("a: %.0f, b: %.0f\n", a, b);
  if (a>b) {
    return 1;
  }
  else if (a<b) {
    return -1;
  }
  return 0;
}