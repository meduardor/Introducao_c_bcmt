#include <stdio.h>


int main()
{
  int dist, quant, consumo;

  printf("Digite a distância:\n");
  scanf("%d", &dist);
  
  printf("Digite a quantidade de gasolina:\n");
  scanf("%d", &quant);

  consumo = dist/quant;

  if(consumo < 8){
    printf("Venda o Carro, %d", consumo);
  }else if(consumo < 14){
    printf("Econômico, %d", consumo);
  }else{
    printf("Super econômico, %d", consumo);
  }
}
