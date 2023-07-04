#include <stdio.h>





int estrutura_repet(int s, int x)
{
  char conv[10];
  
  if (s > x){
    printf("O %d Não pode ser convertido", s);
    return x;
  }else if(s < x){
    printf("Pode-se converter o némero %d", s);

    return sprintf(conv,"%2d", s);
  }
  return 0;
}


int main(void)
{
  int fhar, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

  fhar = lower;
  while(fhar<=upper){
    celsius = 5 * (fhar-32) / 9;
    printf("%d\t%d\n", fhar, celsius);
    fhar += step;
  }

  
}


