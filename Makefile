CC=gcc
CFLAGS=-I.
DEPS = word.h user_input.h
OBJ = word.o hangman_main.o user_input.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hangman: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
