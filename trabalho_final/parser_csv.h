#if !defined (PARSERCSV_H)
#define PARSERCSV_H

// Definição de tipos para utilização de números positivos inteiros;
typedef unsigned int u_int;
typedef unsigned char u_char;

// Constantes
#define MAXLINE 151
#define MAXCOLS 100


/* strcut arrays */

typedef struct{
  char   attr[1][5];
  double chart[150][4];
  char   tipo[150][1];
  
} Data_matrix;

typedef struct {
  float comp_sep[MAXLINE];
  float larg_sep[MAXLINE];  
  float comp_pet[MAXLINE];
  float larg_pet[MAXLINE];
  char tipo[MAXLINE];
  
} Arrays;


// Função para fazer a leitura do documento e inserir dentro da estrutura `arrays`.
char  get_access_data_csv(char *arquivo, char *text[],
			const int max_coluna, int *number_coluna);


int array_comp_sep(char *file, int num_linha, int num_coluna, int coluna,
                   int linha);

void insertion_sort(float *Lst, int n);

int erase(char* arr, int index);

void erase_float(float* array, int tam, int n);

void sortList(float* list, int size);

void atributo_name(char *matriz[151][5], char *arr[], int num_linha, int num_coluna);

int ocorr(char tipos[MAXLINE], char name[], int tamanho);

#endif
