#!/usr/bin/env sh

# Compilador
CC="clang"

#Flags
CFLAGS="-Wall -Wextra -lm -Wformat=2 -Wint-conversion -pedantic -std=c99 -lSDL2 -lpthread"

#lista de scripts
SOURCES="pong.c"

# lIsta de cabeçalhos
HEADERS="pong.h"

#Name Programa
OUTPUT="pong.o"

# Comando de compilação
$CC $SOURCES $CFLAGS $(printf -- "-I%s " $HEADERS) -o $OUTPUT 