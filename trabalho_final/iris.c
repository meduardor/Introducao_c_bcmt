
/*

Instituição: Universidade Federal do Rio de Janeiro;
Curso: BCMT;
Aluno: Marco Eduardo Rodrigues da Silva;
DRE: 
  
 * Referências:
    - Matérias: Slides das Aulas
    - Livros: Entendo Algoritmos
    - Sites:
       - https://imsouza.github.io/posts/algoritmos-de-ordenacao-em-c-1


 * Criar um modelo de aprendizado de máquina capaz de caracterizar uma flor iris.
 * Criar um programa que permita analisar o banco de dados Iris.
 * Dados do Banco de dados

 - banco de dados = formato(cvs);
  - Comprimento da sépala - coluna 1
  - Largura da sepala - coluna 2
  - Comprimento da petala - coluna 3
  - Largura da petala - coluna 4
  - tipo - coluna 5
 
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/types.h>



#include "database.h"
#include "parser_csv.h"


#define ARQUIVO "iris.csv"
#define COLUNAS 755
#define LINHAS 151




// MatrizIris matriz_iris;

int main(void)
{
  
  int num_linha = 0, num_coluna = 0;
  FILE *f;
  f = fopen(ARQUIVO, "r");
  char linha_matriz[LINHAS][COLUNAS];
  char *matriz[LINHAS][COLUNAS];

  
  
   // Caso o arquivo esteja vazio ele retorna essa mensagem de erro.
   if (f == NULL){
    printf("Error");
    return 1;
  }
   // variavel que faz a contagem das celulas da tabela.
  char buffer[COLUNAS];

  // Loop para ler toda as entradas da tabela usando fgets.
  while( fgets(buffer, sizeof(buffer), f) != NULL && num_linha < COLUNAS){
    
    // (strcpy -> para copiar todas as linhas para var num_linha).
    strcpy(linha_matriz[num_linha], buffer);
    
    // Função que precorre todos os dados que estão linha_matriz e formata.
    get_access_data_csv(linha_matriz[num_linha], matriz[num_linha],
			COLUNAS, &num_coluna);
    num_linha++;
  }


  for (int numLinha = 0; numLinha < num_coluna; numLinha++){
        // printf("Coluna: %d\n",numLinha + 1);
        for (int numColuna = 0; numColuna < num_linha; numColuna++){
  	      // printf("%s\n", matriz[numColuna][numLinha]);

        }
  }

  struct Arrays arr;
    

  fclose(f);


  /* char str_list[200]; */
  int menu = 1;
  while(menu != 3){
    
    printf("\n\n --------------------------------------");

    printf("\n [1] Mostrar Estatísticas:");
    printf("\n [2] Classificar as Amostras:");
    printf("\n [3] Sair!");
    printf("\n Escolha uma opção do Menu:");
    scanf("%d",&menu);

    switch(menu) {
    case 1:{
      printf("\n\n Resumo das Estatísticas:\n");
      
      float atual;
      char List;
      float* columns[num_linha];
      float columnSizes[num_coluna];

      for (int i = 0; i < LINHAS; i++){
          arr.comp_sep[i] = matriz[i][0];
          
          List = *strtok(arr.comp_sep[i], ", "); 

          atual = (float)atof(&List);

          for (int col = 0; col < num_coluna; col++) {
              float* column = (float*)malloc(num_linha * sizeof(float));
              for (int row = 0; row < num_linha; row++) {
                  arr.comp_sep[row] = matriz[row][col];
              }
              columns[col] = column;
              columnSizes[col] = num_linha;

              insertion_sort(column, num_linha);
          }
      }
      break;
    }

    case 2:{
      printf("\n\n Classificação das Amostras:\n");
      array_comp_sep(ARQUIVO, num_linha, num_coluna,COLUNAS,LINHAS);
      break;
      
    }

    
    default:{
      printf("Sair!!\n");
      continue;
    }
    }
  }

  return 0;
}
