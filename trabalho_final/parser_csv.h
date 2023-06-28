#if !defined (PARSERCSV_H)
#define PARSERCSV_H

#include <bits/types/FILE.h>


/* strcut arrays */
struct Arrays {
  char comp_sep[151];
  char larg_sep[151];
  char comp_pet[151];
  char larg_pet[151];
  char tipo[151];
  
};

typedef unsigned long int u_int;

// Função para fazer a leitura do documento e inserir dentro da estrutura `arrays`.
int get_access_data_csv(char *arquivo, char *text[],
			const u_int max_coluna, u_int *number_coluna);

int print_matriz_iris(FILE *file, const u_int linha,
		      const u_int coluna,const u_int celula,
		      u_int num_linha, u_int num_coluna);

#endif
