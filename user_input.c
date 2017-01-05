#include <stdio.h>
#include <stdlib.h>
#include <user_input.h>

int guessletter(char *word) {
	/*
	accepted user unput is only small capital letters
	*/

	char letter;
	int guessed = 0;

	/* use system call to make terminal send all keystrokes directly to stdin */
	system ("/bin/stty raw");
	do 
	{
		//printf("\033[2J"); //clear screen
		printf ("\rGuess a letter:  \b");
		scanf ("%c", &letter);
	} while ((letter < 'a') || (letter > 'z'));
	system ("/bin/stty cooked");

	printf("\nDebug: %c\n", letter);

	for (int i = 0; word[i] != '\0'; i++) {
		if (word[i] == letter) {
			guessed++;
		}
	}

	if (guessed > 0) {
		printf ("Debug: guessed %i letters\n", guessed);
	} else {
		printf ("Debug: NONE guessed\n");
	}

	return guessed;
}
