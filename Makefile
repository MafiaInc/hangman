CC=gcc
CFLAGS=-I.
DEPS = word.h
OBJ = word.o hangman_main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hangman: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
