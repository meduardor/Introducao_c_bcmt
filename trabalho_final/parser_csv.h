#ifndef PARSERCSV_H
#define PARSERCSV_H

#include <bits/types/FILE.h>


/* strcut arrays { */
struct Arrays {
  float comp_sep[151];
  float larg_sep[151];
  float comp_pet[151];
  float larg_pet[151];
  char  tipo[151];
  
};

// Função para fazer a leitura do documento e inserir dentro da estrutura `arrays`.
int get_access_data_csv(char *arquivo[], char text, FILE *input);


#endif
