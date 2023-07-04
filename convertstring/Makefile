# Especifica compilador
# CC=clang
CC=gcc


.POSIX:


# definindo as flags de compilação
CFLAGS= -Wall -Wextra -Wformat=2 -Wint-conversion -pedantic -std=c99 -lm

# Especifica os Diretorios onde os arquivos estão localizados

SRCDIR = src
INCDIR = include
OBJDIR = obj


# Definição do nome do Programa
PROGRAM_NAME = $(basename $(notdir $(CURDIR)))

# lista de arquivos de origem
SRC = src/writer.c src/writer.h

# lista de arquivos de cabeçalho
INCLUDES = $(wilcard $(INCDIR)/*.h)

# Saida do Programa 
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

# writer.o: writer.h
$(OBJDIR)/%.o: $(SRC)
	$(CC) -c writer.c -o writer.o $(CFLAGS)


# all: options $(PROGRAM_NAME)
# 	@echo $(PROGRAM_NAME) build options:
# 	@echo "CFLAGS = $(CFLAGS)"
# 	@echo "CC = $(CC)"


# Define as regras de compilação
$(OBJDIR)/%.o: $(SRC)/%.c $(INCLUDES)/%.h 
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o$@

# Define a regra de construção do executável
$(PROGRAM_NAME): $(OBJS) $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $^ -E -o $@

# Define a regra para limpeza de arquivos
clean:
	rm -f $(OBJDIR)/*.o $(PROGRAM_NAME)
