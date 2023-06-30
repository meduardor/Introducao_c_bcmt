#if !defined (DATABASE_H)
#define DATABASE_H


typedef struct {
  char   attr[1][5];
  int    chart[150][4];
  char   tipo[150][1];
  
} MatrizIris;
// Acesso ao banco de dados
int access_database(char *arquivo);

// Fatiando os dadods do banco
int slice_data(void* name);


#endif
