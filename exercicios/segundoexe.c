#include <stdio.h>


int main()
{
  float media, nota1, nota2;
  printf("Digite as duas notas:\n");

  scanf("%f %f", &nota1, &nota2);
  media = (nota1 + nota2)/2;

  printf("Sua media é: %f", media);
}
