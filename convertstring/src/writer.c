#include <stdio.h>
#include <string.h>

#include "writer.h"

// Converte um valor int em um valor string
extern char converf(int value, char str[])
{  
  return sprintf(str,"%02d", value);  
}

// Leitura de string e conacatenação de dois valores.
extern char leia_entrada (char d[3], char c[3], char result[10]) 
{
   scanf("%s/%s", d, c);
  
  strcpy(result, d);
  strcat(result, c); 
   return 0; 
}


extern char* itoa(int value, char* result, int base)
{
  // check that the base if valid
  if (base < 2 || base > 36) { *result = '\0'; return result; }

  char* ptr = result, *ptr1 = result, tmp_char;
  int tmp_value;

  do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
  } while ( value );

  // Apply negative sign
  if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
  return result;
}


