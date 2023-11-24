#include "view.h"
#include "../utils/utils.h"
#include <stdio.h>

void logo() {
  printf ("\n\n");
  printf(" _____  _                   _    _ _ _  _\n");
  printf("|   __|| |_  ___  ___  ___ | |_ | | | ||_| ___  ___\n");
  printf("|__   ||  _||  _|| -_|| -_||  _|| | | || ||_ -|| -_|\n");
  printf("|_____||_|  |_|  |___||___||_|  |_____||_||___||___|\n");
  printf("\n\n\n");
}


void printArquivoNaoExiste(char *filename) {
    char msg_erro[100];
    msg_erro[0] = '\0';
    sprintf (msg_erro, "\nArquivo \"%s\" não existe", filename);
    printAmarelo(msg_erro);
    printf ("\n\n");
}


void printArquivoGerado(char *arquivo) {
  char msg[100];
  msg[0] = '\0';
  sprintf (msg, "\n\nArquivo %s gerado com sucesso!\n\n", arquivo);
  printAmarelo(msg);
}
