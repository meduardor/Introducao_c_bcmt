#include <stdio.h>


int main(void)
{
  int idade;
  char sexo;
  printf("Digite sua idade e seu sexo:\n");
  scanf("%d %c", &idade, &sexo); 
  printf("Sua idade é %d e seu sexo é %c", idade, sexo);
}
