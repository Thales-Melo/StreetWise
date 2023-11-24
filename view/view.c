#include "view.h"
#include "../utils/utils.h"
#include <stdio.h>


void view_logo() {
  printf ("\n\n");
  printf(" _____  _                   _    _ _ _  _\n");
  printf("|   __|| |_  ___  ___  ___ | |_ | | | ||_| ___  ___\n");
  printf("|__   ||  _||  _|| -_|| -_||  _|| | | || ||_ -|| -_|\n");
  printf("|_____||_|  |_|  |___||___||_|  |_____||_||___||___|\n");
  printf("\n\n\n");
}


void view_print_file_nonexistent(char *filename) {
    // char msg_erro[100];
    // msg_erro[0] = '\0';
    // sprintf (msg_erro, "\nArquivo \"%s\" não existe", filename);
    // printAmarelo(msg_erro);
    printf ("\nArquivo %s não existe\n\n", filename);
}

