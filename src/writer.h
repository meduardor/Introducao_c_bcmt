#ifndef WRITER_H
#define WRITER_H

// Definição das leituras stdin
struct values_convert
{
  int mes;
  int dia;
  int ano;
};

char converf(int m);

char conca_string_split(char m, char d);

char* itoa(int value, char* result, int base);

#endif