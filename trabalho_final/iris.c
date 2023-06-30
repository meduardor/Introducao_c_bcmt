
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
#include<string.h>



#include "database.h"
#include "parser_csv.h"


#define ARQUIVO "iris.csv"
#define COLUNAS 755
#define LINHAS 151




// MatrizIris matriz_iris;

int main(void)
{
  
  u_int num_linha = 0, num_coluna = 0;

  int menu = 1;
  while(menu != 3){
    
    printf("\n\n --------------------------------------");

    printf("\n 1 Mostrar Estatísticas:");
    printf("\n 2 Classificar as Amostras:");
    printf("\n 3 Sair!");
    printf("\n Escolha uma opção do Menu:");
    scanf("%d",&menu);

    switch(menu) {
    case 1:{
      printf("\n\n Resumo das Estatísticas:\n");
      matriz_iris(ARQUIVO, LINHAS, COLUNAS, num_linha, num_coluna);
      break;
    }
    case 2:{
      printf("\n\n Classificação das Amostras:");
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
