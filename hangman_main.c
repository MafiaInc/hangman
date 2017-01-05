#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <word.h>
#include <user_input.h>

#define DICTIONARY "dictionary.dat"

void main() {
	srand(time(NULL));

	char *word;
	word = findword(fopen(DICTIONARY, "r"));

	while(strlen(word) < 4) {
		free(word);
		word = findword(fopen(DICTIONARY, "r"));
	}

	printf("Debug: %s\n", word);

    guessletter(word);

	free(word);
}
