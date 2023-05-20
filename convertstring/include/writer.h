#ifndef WRITER_H
#define WRITER_H

// Definição das leituras stdin
struct values_convert 
{ 
  int value_in;
  int value_o;
  char* conver;
};

char converf(int value, char str[]);
char conca_string_split(char m, char d);
char* itoa(int value, char* result, int base);
char leia_entrada (char d[3], char c[3], char result[10]); 

#endif

