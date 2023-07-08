
#include <stddef.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <sys/select.h>

#include "database.h"
#include"parser_csv.h"


float cal_media(float arr[], int size) {
    float soma = 0;
    for (int i = 0; i < size; i++) {
        soma += arr[i];
    }
    return soma / size;
}


float cal_dev_pad(float arr[], int tam, float media)
{
  float soma = 0;

  for (int i = 0; i < tam; i++){
    soma += pow(arr[i] - media, 2);
  } 
  return sqrt(soma / tam);
}


int totalElemet(int total_linha, int total_colunas) {
  int contador = 0;

  for (int i = 0; i < total_linha; i++){

    for (int j = 0; j < total_colunas; j++){
      contador++;
    }
    
  }
  return contador;
}

// Função que que printa o maior e menor valor de um array
void max_min(float arr[], int tam, float *max, float *min) {
  *max = arr[0];
  *min = arr[0];


  for (int i = 1; i < tam; i++){

    if (arr[i] > *max){
      *max = arr[i];
    }
    if (arr[i] <= *min){
      *min = arr[i+1];
    }
  }
}


// Função o número maximo da matrix
float max_matriz(float arr[], int tam) {
  int col = 0;
  float max = arr[col]; 

  for (col = 1; col < tam; col++){
    max = arr[col];
    if (arr[col] > max){
      max = arr[col];
    }
    
  }
  return max;
}

// Função que retorna o menor valor do array 
// TODO:Erro no retorno dp valor 
float min_matriz(float arr[], int tam) {
  int col;
  float min; 

  for (col = 1; col < tam; col++){
    if (arr[col] < min){
      min = arr[col];
    }
    
  }
  return min;
}
