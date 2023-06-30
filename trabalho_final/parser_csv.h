#if !defined (PARSERCSV_H)
#define PARSERCSV_H

// Definição de tipos para utilização de números positivos inteiros;
typedef unsigned int u_int;
typedef unsigned char u_char;

// Constantes
#define Max_line 755
#define Max_cols 100

/* strcut arrays */
typedef struct  {
  u_int matrix[Max_line][Max_cols];
  int num_line;
  int num_cols;
}Arrays;


// Função para fazer a leitura do documento e inserir dentro da estrutura `arrays`.
int get_access_data_csv(char *arquivo, char *text[],
			const u_int max_coluna, u_int *number_coluna);

u_int matriz_iris(char *file, const u_int linha,
		 const u_int coluna, u_int num_linha, u_int num_coluna);

u_int separate_in_array(Arrays arr);

#endif
