
#include <stdio.h>
#include "database.h"

int access_database(int matriz[150][5], char arquivo[], FILE *input, char text)
{
  float n, m;
  input = fopen(arquivo, "r");
  if(input == NULL){printf("Error");}

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      printf("%d", matriz[i][j]);
    }
  }
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