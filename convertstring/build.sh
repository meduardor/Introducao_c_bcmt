#!/usr/bin/env sh

CC="clang"

# Lista de arquivos .c
SOURCES="src/main.c src/writer.c"


# Lista de Cabeçalhos
HEADERS="src/writer.h"

# Opções de compilação
CFLAGS="-Wall -Wextra -Wformat=2 -Wint-conversion -pedantic -std=c99 -lm"


# SRC="src/writer.c"
# OUT="obj/writer.o"

# Nome do executável
OUTPUT="src/conversion"

# Comando de compilação

# $CC $SRC -o $OUT $CFLAGS -I$HEADERS

$CC $SOURCES $CFLAGS $(printf -- "-I%s " $HEADERS) -o $OUTPUT  

# gcc $SOURCES -o $OUTPUT $CFLAGS -I$HEADERS

# Fim da compilação


