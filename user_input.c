#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int guessletter(char *word) {
	/*
	accepted user unput is only small capital letters
	*/

	char letter;

	/* use system call to make terminal send all keystrokes directly to stdin */
	system ("/bin/stty raw");
	do 
	{
		//printf("\033[2J"); //clear screen
		printf("\rGuess a letter:  \b");
		scanf("%c", &letter);
	} while ((letter < 'a') || (letter > 'z'));
	system ("/bin/stty cooked");

	printf("\nDebug: %c\n", letter);

	return 0;
}

void main() {
	char *word;

	guessletter(word);
}
