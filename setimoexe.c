#include <stdio.h>
#include <string.h>



int main()
{
  int dia, mes;
  int ano;

  char dia_s[2], mes_s[2];


  printf("Digite o dia do aniversario:\n");
  scanf("%d", &dia);

  printf("Digite o Mês do seu aniversario:\n");
  scanf("%d", &mes);

  printf("Digite o Ano do seu aniversario:\n");
  scanf("%d", &ano);


  itoa(dia, dia_s, 2);

  

  printf("test %d, %d, %d", dia, mes, ano);

  return 0;
}
