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


int erase(char* arr, int index) {


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

void erase_float(float *array, int tam, int n) {
  if (n >= 0 && n < tam){
    for (int i = n; i < tam - 1; i++){
      array[i] = array[i + 1];
    }
  }
}




// Função para ordenar uma lista de inteiros em ordem crescente
void sortList(float* list, int size) {
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

int array_comp_sep(char *file, int num_linha, int num_coluna, int coluna, int linha) {

    FILE *f = fopen(file, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int matrix[linha][coluna];
    num_coluna = 0;
    num_linha = 0;

    // Ler o arquivo e armazenar os valores na matriz
    char line[coluna];
    while (fgets(line, sizeof(line), f)) {
        char* token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
	  matrix[num_linha][col] = (float)atof(token);
            token = strtok(NULL, ",");
            col++;
        }
        num_coluna = col;
        num_linha++;
    }

    // Fechar o arquivo
    fclose(f);

    // Transferir cada coluna para uma lista distinta e ordenar os valores
    float* columns[num_linha];
    float columnSizes[num_coluna];

    for (int col = 0; col < num_coluna; col++) {
        float* column = (float*)malloc(num_linha * sizeof(float));
        for (int row = 0; row < num_linha; row++) {
            column[row] = matrix[row][col];
        }
        columns[col] = column;
        columnSizes[col] = num_linha;

        insertion_sort(column, num_linha);
    }

    // Imprimir as listas ordenadas
    for (int col = 0; col < num_coluna; col++) {
        printf("Coluna %d ordenada:\n", col + 1);
        for (int i = 0; i < columnSizes[col]; i++) {
            printf("%f\n", columns[col][i]);
        }
        printf("\n");
    }

    // Liberar a memória alocada para as listas
    for (int col = 0; col < num_coluna; col++) {
        free(columns[col]);
    }

    return 0;
}
