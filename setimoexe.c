
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void diaAniver (char d[2]) { scanf(" %[^\n]s", d); }

void mesAniver (char x[2]) { scanf(" %s", x); }

int main()
{
  int dia, ano;

  char dia_s[2];
  char mes_s[2];

  // Dia do aniversario
  printf("Digite o Dia do aniversario:\n");
  diaAniver(dia_s);

  // Mês do aniversario
  printf("Digite o Mês do seu aniversario:\n");
  mesAniver(mes_s);

  // Ano do aniversario.  
  printf("Digite o Ano do seu aniversario:\n");
  scanf("%d", &ano);

  // Teste de saida 
  printf("Dia:%s,Mes:%s\n", dia_s, mes_s);
  
  // concatenação dos elementos 
  strcat(dia_s, mes_s);
  
  int valor = atoi(dia_s);
  int result = valor + ano;

  printf("%d, %d \n", valor, result);
  
  return 0;
}
