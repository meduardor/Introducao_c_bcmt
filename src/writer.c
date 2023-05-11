#include <stdio.h>
#include <string.h>

#include "writer.h"

// "Class" -> FIXME: change name
struct values_convert value;

// Converte um valor int em um valor string
char converf(int m)
{
  m = value.mes;
  scanf("%d", &m);
  
  char mes[2];
  char result = sprintf(mes,"%d", m); 
  
  return result;
}

// Concatena duas strings
char conca_string_split(char m, char d)
{
  
  char* result = strcat(m, d);
  
  return *result;
}

// Converte um valor integer em um valor string 
// Uma forma um pouco mais eficiente que a primeira função convertf
char* itoa(int value, char* result, int base)
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