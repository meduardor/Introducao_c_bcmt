
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
#include <string.h>
#include <sys/types.h>



#include "database.h"
#include "parser_csv.h"


#define ARQUIVO "iris.csv"
#define COLUNAS 5
#define LINHAS 151
#define CELS 755




// MatrizIris matriz_iris;

int main(void)
{
  

  
  int num_linha = 0, num_coluna = 0;
  FILE *f;
  f = fopen(ARQUIVO, "r");
  char linha_matriz[LINHAS][CELS];
  char *matriz[LINHAS][COLUNAS];

  
  
  // Caso o arquivo esteja vazio ele retorna essa mensagem de erro.
  if (f == NULL){printf("Error"); return 1;}

  // variavel que faz a contagem das celulas da tabela.
  char buffer[CELS];

  // Loop para ler toda as entradas da tabela usando fgets.
  while( fgets(buffer, sizeof(buffer), f) != NULL && num_linha < LINHAS){
    // (strcpy -> para copiar todas as linhas para var num_linha).
    strcpy(linha_matriz[num_linha], buffer);
  
    // Função que precorre todos os dados que estão linha_matriz e formata.
    get_access_data_csv(linha_matriz[num_linha], matriz[num_linha],
		  COLUNAS, &num_coluna);
    num_linha++;

    
  }

  fclose(f);

  float entrada[LINHAS];
  int total_linha_2 = sizeof(entrada)/sizeof(entrada[0]);
  /* int total_colunas = sizeof(matriz[0])/sizeof(matriz[0][0]); */
  for (int i = 0; i <num_linha; i++){
    entrada[i] = atof(matriz[i][0]);
  }
  
  float max_t = max_matriz(entrada, total_linha_2);
  float min_t = min_matriz(entrada, total_linha_2);
  printf("%d | %.1f | %.1f\n", total_linha_2, max_t, min_t);

  //----------------------------------------------///
  
  char *name_one[COLUNAS];
  char *name_two[COLUNAS];
  char *name_tree[COLUNAS];
  char *name_four[COLUNAS];
  char *name_five[COLUNAS];
  
  for(int i =  0; i < num_linha; i++){
    for (int j = 0; j < num_coluna; j++){
      name_one[j] = matriz[0][j];
      name_two[j] = matriz[0][j+1];
      name_tree[j] = matriz[0][j+2];
      name_four[j] = matriz[0][j+3];
      name_five[j] = matriz[0][j+4];
    }
  }

 
  /* printf("%s\n",*name_two); */
  /* printf("%s\n",*name_tree); */
  /* printf("%s\n",*name_four); */
  //printf("%s\n",*name_five);
  
  float col_comp_sep[LINHAS];
  float col_larg_sep[LINHAS];
  float col_comp_pet[LINHAS];
  float col_larg_pet[LINHAS];
  char *col_tipo[LINHAS];

 
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
      printf("\n --------------------------- \n");
      for(int i = 1; i < num_linha; i++){
	      col_comp_sep[i] = atof(matriz[i][0]);
	      col_larg_sep[i] = atof(matriz[i][1]);
	      col_comp_pet[i] = atof(matriz[i][2]);
	      col_larg_pet[i] = atof(matriz[i][3]);
	      col_tipo[i]     = matriz[i][4];

      }

      float maior, menor;
     
      int total_linha = sizeof(matriz)/sizeof(matriz[0]);
      int total_colunas = sizeof(matriz[0])/sizeof(matriz[0][0]);

      // Comprimento da Sepala
      int tam_com_sep = sizeof(col_comp_sep)/sizeof(col_comp_sep[0]);
      max_min(col_comp_sep, tam_com_sep, &maior, &menor);
      float min_t = encontrarMenorValor(col_comp_sep, tam_com_sep);
      int TotalElementos = totalElemet(total_linha, total_colunas);
      float media = cal_media(col_comp_sep,LINHAS);
      float desvio = cal_dev_pad(col_comp_sep, LINHAS, media);

      
      printf("Resumo da Base Iris: %d elementos\n",TotalElementos);
      printf("%s:\n",*name_one);
      printf("Mínimo: %.1f | %.1f\n",menor, min_t);
      printf("Máximo: %.1f\n",maior);      
      printf("Média: %f\n", media);
      printf("Desvio padrão: %f\n", desvio);

      // Largura da Sepala
      int tam_larg_sep = sizeof(col_larg_sep)/sizeof(col_larg_sep[0]);
      max_min(col_larg_sep, tam_larg_sep, &maior, &menor);
      float media_larg = cal_media(col_larg_sep,LINHAS);
      float desvio_larg = cal_dev_pad(col_larg_sep, LINHAS, media_larg);

      printf("%s:\n",*name_two);
      printf("Mínimo: %.1f\n",menor);
      printf("Máximo: %.1f\n",maior);      
      printf("Média: %f\n", media_larg);
      printf("Desvio padrão: %f\n", desvio_larg);

      //Comprimento da petala
      int tam_comp_pet = sizeof(col_comp_pet)/sizeof(col_comp_pet[0]);
      max_min(col_comp_pet, tam_comp_pet, &maior, &menor);
      float media_pet = cal_media(col_comp_pet,LINHAS);
      float desvio_pet = cal_dev_pad(col_comp_pet, LINHAS, media_pet);

      printf("%s:\n",*name_tree);
      printf("Mínimo: %.1f\n",menor);
      printf("Máximo: %.1f\n",maior);      
      printf("Média: %f\n", media_pet);
      printf("Desvio padrão: %f\n", desvio_pet);

      // Largura da petala
      int tam_larg_pet = sizeof(col_larg_pet)/sizeof(col_larg_pet[0]);
      max_min(col_larg_pet, tam_larg_pet, &maior, &menor);
      float media_larg_pet = cal_media(col_larg_pet,LINHAS);
      float desvio_larg_pet = cal_dev_pad(col_larg_pet, LINHAS, media_larg_pet);

      printf("%s:\n",*name_four);
      printf("Mínimo: %.1f\n",menor);
      printf("Máximo: %.1f\n",maior);      
      printf("Média: %f\n", media_larg_pet);
      printf("Desvio padrão: %f\n", desvio_larg_pet);
      printf("\n");
      
      // Tipos de IRIS
      int tam_tipo = sizeof(col_tipo)/sizeof(col_tipo[0]);
      char name_1[] = "setosa";
      char name_2[] = "versicolor";
      char name_3[] = "virginica";
      int setosa = ocorr(col_tipo, name_1, tam_tipo);
      int versicolor = ocorr(col_tipo, name_2, tam_tipo);
      int virginica = ocorr(col_tipo, name_3, tam_tipo);
      //
      printf("%s", *name_five);
      printf("Setosa: %d ocorrências\n", setosa);
      printf("Versicolor: %d ocorrências\n", versicolor);
      printf("Virginica: %d ocorrências\n", virginica);
      printf("\n");

      break;
    }

    case 2:{
      printf("\n\n Classificação das Amostras:\n");
      // array_comp_sep(ARQUIVO, num_linha, num_coluna,COLUNAS,LINHAS);
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
