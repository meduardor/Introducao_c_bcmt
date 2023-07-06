#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "database.h"
#include "parser_csv.h"


/*Parser documento CSV*/

char get_access_data_csv(char *linha, char *coluna[],
			const int max_coluna, int *num_coluna)
{
  
  *num_coluna = 0;
  char *separa = strtok(linha, ",");
  
  while (separa != NULL && *num_coluna < max_coluna) {
    coluna[*num_coluna] = separa;
      separa = strtok(NULL, ",");
      (*num_coluna)++;
  }

  return 0;
  
}


void insertion_sort(float *Lst, int n )
{
  int atual, j;

  for (int i = 0; i < n; i++){
    atual = Lst[i];
    for (j = i; (j > 0) && (atual < Lst[j -1]); j--){
      Lst[j] = Lst[j -1];
    }
    Lst[j] = atual;
  }
 
}

// Apaga um elemento char em uma string
int erase(char* arr, int index)
{
  int tamanho = strlen(arr);
  if (!arr) return 0;
  if (arr == 0) return 0;
  if (index < 0 || index >= tamanho) return 0;

  arr--;
  if (index >= 0 && index < tamanho){
    for (int i = index; i < tamanho; i++){
      arr[i] = arr[i+1];
    }
    arr[tamanho -1] = '\0';
  }
  
  return 1;
}

// Apaga um elemento float dentro de um array
void erase_float(float *array, int tam, int n)
{
  if (n >= 0 && n < tam){
    for (int i = n; i < tam - 1; i++){
      array[i] = array[i + 1];
    }
  }
}

// Função para ordenar uma lista de float  em ordem crescente
void sortList(float* list, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}


void atributo_name(char *matriz[151][5], char *arr[],
		   int num_linha, int num_coluna) {

  for(int i = 0; i < num_linha; i++){
    for(int j = 0; j < num_coluna; j++){
      *arr[j] = *matriz[0][j];
      
    }
  }
  
}

// TODO(Marco):Conserta leitura de ocorrencia dos valores `char`
int ocorr(char tipos[MAXLINE], char name[], int tamanho)
{
  int contador = 0; 
  int i, j;
  /* char *n; */
  /* n = name; */
  for (i = 0; i < tamanho; i++){
    /* n = tipos[i]; */
    for (j = 0; j<strlen(name); j++){
      if(tipos[i] == name[i]){
        contador++;
      }
    }
  }
  return contador;
}
