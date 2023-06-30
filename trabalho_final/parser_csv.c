#include <stdio.h>
#include <string.h>
#include "parser_csv.h"


#include <bits/types/FILE.h>



Arrays arr;

/*Parser documento CSV*/

int get_access_data_csv(char *linha, char *coluna[],
			const u_int max_coluna, u_int *num_coluna)
{
  
  *num_coluna = 0;
  char *separa = strtok(linha, ",");
  
  while (separa != NULL && *num_coluna < max_coluna) {
      coluna[*num_coluna] = separa;
      (*num_coluna)++;
      separa = strtok(NULL, ",");
  }
 
  return 0;
}

// Função que retorna a matriz iris dentro de um array

u_int matriz_iris(char *file, const u_int linha, const u_int coluna,
		u_int num_linha, u_int num_coluna)
 {
   FILE *f;
   f = fopen(file, "r");
   char linha_matriz[linha][coluna];
   char *matriz[linha][coluna];

   // Caso o arquivo esteja vazio ele retorna essa mensagem de erro.
   if (file == NULL){
    printf("Error");
    return 1;
  }
   // variavel que faz a contagem das celulas da tabela. 
  char buffer[coluna];

  // Loop para ler toda as entradas da tabela usando fgets.
  while( fgets(buffer, sizeof(buffer), f) != NULL && num_linha < coluna){
    // (strcpy -> para copiar todas as linhas para var num_linha).
    strcpy(linha_matriz[num_linha], buffer);
    // Função que precorre todos os dados que estão linha_matriz e formata.
    get_access_data_csv(linha_matriz[num_linha], matriz[num_linha],
			coluna, &num_coluna);
    num_linha++;

    u_int tam = sizeof(linha_matriz)/sizeof(linha_matriz[0]); 

    for (u_int numLinha = 0; numLinha < tam; ++numLinha){
      u_int *row = arr.matrix[numLinha];
      printf("%d\n",row);
      for (u_int numColuna = 0; numColuna < tam; ++numColuna){
      	u_int value = row[numColuna];
	      printf("%d\n",value);
      }
      return *row;
    }
}

  fclose(f);

  for (u_int i = 0; i < num_coluna; i++){
    printf("Colunas: %d\n", i + 1);
    for (u_int j = 0; j < num_linha; j++){
      printf("%s\n", matriz[j][i]);
      
    }
    printf("\n");
  }

  return 0;
}
