#!/usr/bin/env sh


## Compilador 
# CC="clang"
CC="gcc"


## Flags 
CFLAGS="-Wall -Wextra -lm -Wformat=2 -Wint-conversion -pedantic -std=c99" 


## Lista dos arquivos C
SOURCES="iris.c database.c parser_csv.c"


## Lista dos Headers
HEADERS="database.h parser_csv.h"


## Nome do Programa

OUTPUT="iris.o"

## Comando de Compilação

$CC $SOURCES $CFLAGS $(printf -- "-I%s" $HEADERS) -o $OUTPUT
