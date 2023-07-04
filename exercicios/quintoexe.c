/*
Crie um programa em C para calcular a média final de uma aluno considerando as seguintes regras:

➢Serão aplicadas três provas: uma no meio do curso (P1), uma no final do curso (P2) 
e uma prova suplementar (Ps ), com todo o conteúdo da disciplina. 

➢ Além das provas, será proposto um trabalho prático de implementação (T). 
➢O cálculo da média final do aluno será feito através da seguinte equação:

 Mf = ((N1 + N2)/2 ∗ 0.8) + (T ∗ 0.2)
*/

#include <stdio.h>


#define m (22*6)


int main()
{
  // P1, P2-> Periodo normal;
  // Ps-> Prova complentar;
  // T-> Trabalho, parte da prova regular;

  float p1, p2, ps, t, nf;
  int freq;
  // Nota 1
  printf("Inserir as notas da prova1:\n");
  scanf("%f", &p1);

  // Nota 2
  printf("Inserir as notas da prova2:\n");
  scanf("%f", &p2);

  // Trabalho
  printf("Inserir as notas do Trabalho:\n");
  scanf("%f", &t);

  // Calculo da Média
  float mf = ((p1 + p2)/2 * 0.8) + (t * 0.2);

  // Calculo de Porcetagem
  printf("Digite os dias frequantados:\n");

  scanf("%d", &freq);

  freq = ((float)freq/100)*m;


  if (mf >= 7.0){

    printf("Aluno não precisa de prova final: sua nota %.1f\n", mf);

  } else if(mf > 3.0 && mf < 7.0){
    printf("Sua média foi: %.1f\n", mf);
    printf("O aluno terá que fazer Prova Final:\n" );

    scanf("%f", &ps);
    nf = (mf + ps)/2;
    printf("Sua nota final é %.1f\n", nf);

      if(nf == 5.0 || freq >= 75){

	printf("Aluno aprovado: Nota final(%.1f), Frêquencia(%d)\n", nf, freq);

      }else{

	printf("Aluno reporvado: Nota final(%.1f), Frêquencia(%d)\n", nf, freq);

     }
  }else{
    printf("Aluno Reprovado, sua média foi %.1f, e sua frêquancia %d\n", mf, freq);
  }

}
