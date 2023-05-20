/*Exercícios do curso de introdução a C/C++ (BCMT-UFRJ)*/

#include <stdio.h>



int kelvin(float cel, float far, int kel)
{
  return 0;
}



int main()
{
  float far, cel;

  printf("Digite a temperatura em Fahrenheit, para conversão:\n");

  scanf("%f", &far);
  cel = (far - 32) * ((float)5 / 9);

  printf("A temperatura em Celsius é: %f", cel);
}


