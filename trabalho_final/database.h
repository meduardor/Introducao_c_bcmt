#if !defined (DATABASE_H)
#define DATABASE_H

#include "parser_csv.h"


// Funções     

float cal_media(float arr[], int size);
float cal_dev_pad(float arr[], int tam, float media);

int totalElemet(int total_linha, int total_colunas);

void max_min(float arr[], int tam, float *max, float *min);
float tam_list(float arr[]);

float max_matriz(float arr[], int tam);
float min_matriz(float arr[], int tam);
float encontrarMenorValor(float array[], int tamanho);

#endif
