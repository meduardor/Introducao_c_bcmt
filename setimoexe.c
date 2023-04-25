
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
  int dia, mes;
  int ano;

  char dia_s[2], mes_s[2];


  printf("Digite o dia do aniversario:\n");
  scanf("%d", &dia);
  sprintf(dia_s,"%d",dia);

  printf("Digite o Mês do seu aniversario:\n");
  scanf("%d", &mes);
  //FIXME: Retorno da string esta acresntando um valor no 0.
  sprintf(mes_s,"%d", mes);

  printf("Digite o Ano do seu aniversario:\n");
  scanf("%d", &ano);

  // concatenação dos elementos 
  strcat(dia_s, mes_s);

  
  int valor = atoi(dia_s);
  int result = valor + ano;

  printf("%d, %d \n", valor, result);
  
  return 0;
}
