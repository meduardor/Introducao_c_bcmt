
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/writer.h"



/* void mesAniver (char x[2]) { scanf(" %s", x); } */

int main()
{
  int dia, mes, ano;

  char dia_s[3], mes_s[3], resultado_s[3];

  // Dia do aniversario
  printf("Digite o Dia do aniversario:\n");
  
  int valor = atoi(dia_s);
  int result = valor + ano;

  printf("%d, %d \n", valor, result);
  
  return 0;
}
