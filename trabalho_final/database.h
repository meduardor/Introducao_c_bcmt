#if !defined (DATABASE_H)
#define DATABASE_H

#include <bits/types/FILE.h>
struct MatrizIris{

  char   attr[1][5];
  int    chart[150][4];
  char   tipo[150][1];
  
};

// Acesso ao banco de dados
int access_database(char arquivo[], FILE *input, char text);

// Fatiando os dadods do banco
int slice_data(void* name);


#endif
