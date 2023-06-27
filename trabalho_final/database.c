
#include <stddef.h>
#include <stdio.h>
#include "database.h"

int access_database(int matriz[150][5], char arquivo[], FILE *input, char text)
{
  float n = 0.0, m = 0.0;
  input = fopen(arquivo, "r");
  if(input == NULL){printf("Error");}

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      printf("%d", matriz[i][j]);
    }
  }
  return 0;
}


float get_data_caracteres(int matriz[150][4], float n, float m)
{
  
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%d", matriz[i][j]);
    }
  }
  
  return 0;
}
