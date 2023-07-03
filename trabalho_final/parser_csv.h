#if !defined (PARSERCSV_H)
#define PARSERCSV_H

// Definição de tipos para utilização de números positivos inteiros;
typedef unsigned int u_int;
typedef unsigned char u_char;

// Constantes
#define Max_line 152
#define Max_cols 100


/* strcut arrays */
typedef struct {
  char   attr[1][5];
  int   chart[150][4];
  char   tipo[150][1];
  
} MatrizIris;


struct Arrays {
  char * comp_sep[Max_line];
  char *larg_sep[Max_line];  
  char *comp_pet[Max_line];
  char *larg_pet[Max_line];
  char *tipo[Max_line];
  
};

typedef struct array {
  int size;
  int max;
  int *v;
} Array;



// Função para fazer a leitura do documento e inserir dentro da estrutura `arrays`.
char  get_access_data_csv(char *arquivo, char *text[],
			const int max_coluna, int *number_coluna);


int array_comp_sep(char *file, int num_linha, int num_coluna, int coluna,
                   int linha);

void insertion_sort(float *Lst, int n);

int erase(char* arr, int index);

void erase_float(float* array, int tam, int n);

void sortList(float* list, int size);


#endif
