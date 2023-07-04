
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "writer.h"


int main(void)
{
  int dia, mes, ano;

  char dia_s[3], mes_s[3], result_s[10];

  // Entra dos valores 
  printf("Digite o dia, mês e ano do seu aniversário (DD/MM/AAAA): \n");
  scanf("%d/%d/%d", &dia, &mes, &ano);

  // Lista dos inteiros
  printf("O dia é %d, o mês %d e o ano %d\n", dia, mes, ano);

  // Conversão de int -> string
  converf(dia, dia_s);
  converf(mes, mes_s);

  // Concateneção de valores.
  strcpy(result_s, dia_s);
  strcat(result_s, mes_s);


  int valor = atoi(result_s);
  int result = valor + ano;

  printf("%d, %d \n", valor, result);

  char recebe[10];
  converf(result, recebe);

  // Separar do result em duas variaveis int "%0d, %0d"
  strncpy(dia_s, recebe, 2);
  // Separação dos dois dígitos finais da soma
  int d1 = result % 10;
  int d2 = (result / 10) % 10;

  // Exibição do resultado
  printf("Soma: %d\n", result);
  printf("Primeiro elemento: %d\n", d1);
  printf("Segundo elemento: %d\n", d2);




  return 0;
}
