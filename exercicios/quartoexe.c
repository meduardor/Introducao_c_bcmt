/*Dadas as medidas dos catetos de um triângulo retângulo, 
informe a medida da hipotenusa. [Dica: para calcular a 
raiz quadrada use a função sqrt(), definida no arquivo math.h]*/


#include <stdio.h>
#include <math.h>


int main()
{
  // h -> hipotenusa, c1, c2 -> catetos

  double h, c1, c2;


  printf("Digite o valor do cateto 1:\n");
  scanf("%lf", &c1);

  printf("Digite o valor do cateto 2:\n");
  scanf("%lf", &c2);

  // Results
  h = sqrt(pow(c1, 2) + pow(c2, 2));
  printf("O valor da Hipotenusa é: %.2lf", h);

  return 0;
}