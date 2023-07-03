#if !defined (DATABASE_H)
#define DATABASE_H


#define MAX_ROWS 755
#define MAX_COLS 200


typedef struct {
    double data[MAX_ROWS];
    int size;
} ColumnData;

typedef struct {
        ColumnData data[MAX_COLS];
        int size;
    } CSVData;


// Funções     
void data_set();

double calc_moda_iris();
double calc_mediana_iris();
double calc_media_iris();
double calc_desvio_padrao_iris();


#endif
