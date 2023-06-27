#include <stdio.h>
#include <string.h>
#include "parser_csv.h"

struct Arrays arr;
/*Parser documento CSV*/

#define ARQUIVO "iris.csv"

int get_access_data_csv(char *arquivo[], char *text, int *number_coluna)
{

  // input = fopen(ARQUIVO, "r");

  // if (input == NULL ){
  //   printf("Error\n");
  //   return 1;
  // }
  
  *number_coluna = 0;
  char *token = strtok(text, ",");
  
  while (token != NULL && *number_coluna < 151) {
      arquivo[*number_coluna] = token;
      (*number_coluna)++;
      token = strtok(NULL, ",");
  }
 
  return 0;
}
