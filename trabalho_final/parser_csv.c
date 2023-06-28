#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "parser_csv.h"

struct Arrays arr;

/*Parser documento CSV*/

int get_access_data_csv(char *linha, char *coluna[],
			const u_int max_coluna, u_int *number_coluna)
{
  
  *number_coluna = 0;
  char *token = strtok(linha, ",");
  
  while (token != NULL && *number_coluna < max_coluna) {
      coluna[*number_coluna] = token;
      (*number_coluna)++;
      token = strtok(NULL, ",");
  }
 
  return 0;
}

// Função que retorna a matriz iris dentro de um array

int print_matriz_iris(FILE *file, const u_int linha,
		      const u_int coluna, const u_int celula,
		      u_int num_linha, u_int num_coluna)
 {
   char linha_matriz[linha][coluna];
   char * matriz[linha][celula];


   if (file == NULL){
    printf("Error");
    return 1;
  }
 
  char buffer[celula];
  
  while( fgets(buffer, sizeof(buffer), file) != NULL && num_linha < coluna){
    strcpy(linha_matriz[num_linha], buffer);
    get_access_data_csv(linha_matriz[num_linha], matriz[num_linha],
			coluna, &num_coluna);
    num_linha++;
  
    
  }

  fclose(file);


  
  for (u_int i = 0; i < num_coluna; i++){
    printf("Colunas: %ld\n", i + 1);
    for (u_int j = 0; j < num_linha; j++){
      printf("%s\n", matriz[j][i]);
      
    }
    printf("\n");
  }

  return 0;
}
