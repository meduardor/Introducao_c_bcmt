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
#include "database.h"

#define ARQUIVO "iris.csv"
// MatrizIris matriz_iris;

int main(void)
{
  char arq[] = ARQUIVO;
  FILE *input;
  char ch;
  int matriz[150][5];
  access_database(matriz, arq,input ,ch);

  
 
  return 0;
}