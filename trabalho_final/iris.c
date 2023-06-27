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

#define MAX_ROWS 151

// MatrizIris matriz_iris;

int main(void)
{
  char *arq[MAX_ROWS];
  FILE *input = NULL;
  char *ch = NULL;
  int *matriz = NULL;
  //access_database(matriz, arq,input ,ch);
  get_access_data_csv(arq, ch ,matriz); 
  return 0;
}
