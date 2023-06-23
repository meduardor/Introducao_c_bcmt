#!/usr/bin/env sh


## Compilador 
CC="clang"

## Flags 
CFLAGS="-Wall -Wextra -lm -Wformat=2 -Wint-conversion -Wnewline-eof -pedantic -std=c99" 


## Lista dos arquivos C
SOURCES="iris.c database.c"


## Lista dos Headers
HEADERS="database.h"


## Nome do Programa

OUTPUT="iris.o"

## Comando de Compilação

$CC $SOURCES $CFLAGS $(printf -- "-I%s" $HEADERS) -o $OUTPUT