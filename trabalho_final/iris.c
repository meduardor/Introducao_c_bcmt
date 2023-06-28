// Criar um programa que permita analisar o banco de dados Iris.
// Criar um modelo de aprendizado de máquina capaz de caracterizar uma flor iris.

/*  banco de dados = formato(cvs);
*  Dados do Banco de dados

  Comprimento da sépala - coluna 1
  Largura da sepala - coluna 2
  
  Comprimento da petala - coluna 3
  Largura da petala - coluna 4

  tipo - coluna 5
 
*/

#include <stdio.h>
#include<string.h>

#include "database.h"
#include "parser_csv.h"



#define ARQUIVO "iris.csv"
#define COLUNAS 755
#define LINHAS 200
#define CELULAS 755

// MatrizIris matriz_iris;

int main(void)
{
  FILE *input = NULL;
  input = fopen(ARQUIVO,"r");
  /* char *matriz[LINHAS][COLUNAS]; */
  /* char linha[LINHAS][CELULAS]; */
  u_int num_linha = 0, num_coluna = 0;
  
  
  /* get_access_data_csv(arq, linha, num_linha);  */

  print_matriz_iris(input, LINHAS, COLUNAS, CELULAS, num_linha, num_coluna);
  return 0;
}
