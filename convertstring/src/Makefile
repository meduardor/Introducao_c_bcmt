CC= clang
.Posix:

writer.o: writer.c writer.h
	$(CC) -c writer.c -o writer.o

conversion: main.c writer.o
	$(CC) -c main.c writer.o -o conversion
