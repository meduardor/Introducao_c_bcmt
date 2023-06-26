#include <stdio.h>
#include "parser_csv.h"

struct Arrays arr;
/*Parser documento CSV*/


int get_access_data_csv(char arquivo[], char text, FILE *input )
{

  input = fopen(arquivo, "r");

  if (input == NULL ){
    printf("Error");
  }

  

  return 0;
}
