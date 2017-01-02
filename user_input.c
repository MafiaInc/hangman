#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <pcre.h>

int guessletter(char *word) {
	//int letter = getchar();

	char *regex;
	pcre *reCompiled;
	const char *pcreErrorStr;
	int pcreErrorOffset;
	int subStrVec[30];
	int pcreExecRet;
	char letter[2];
//	char *fgets(char *s, int size, FILE *stream

	// compile regex (credit: pcre_example.c)
	regex = "[a-z]";
	reCompiled = pcre_compile(regex, 0, &pcreErrorStr, &pcreErrorOffset, NULL);

	if (reCompiled == NULL) {
		printf("ERROR: Could not compile '%s': %s\n", regex, pcreErrorStr);
		exit(1);
	}

	if(pcreErrorStr != NULL) {
		printf("ERROR: Could not study '%s': %s\n", regex, pcreErrorStr);
		exit(1);
	}

	/* use system call to make terminal send all keystrokes directly to stdin */
	system ("/bin/stty raw");
	do 
	{
		//printf("\033[2J"); //clear screen
		printf("\rGuess a letter:  \b");
		fgets(letter, 2, stdin);
		pcreExecRet = pcre_exec(reCompiled,
								NULL,      // no regex optimizations
								letter, 
								2,         // length of string
								0,         // Start looking at this point
								0,         // OPTIONS
								subStrVec,
								30);       // Length of subStrVec
	} while (pcreExecRet <= 0);
	system ("/bin/stty cooked");

	pcre_free(reCompiled);

	printf("\nDebug: %c\n", letter[0]);

	return 0;
}

void main() {
	char *word;

	guessletter(word);
}
