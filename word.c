#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <word.h>

#define BUFFER_SIZE 255 //set to expected max line length

char *findword(FILE *df) {
	/* 
	This function reads a provided txt file and
	returns address of allocated memory where
	random line content of that file is stored

	set srand(time(NULL)) before calling for rand()
	*/
	int count = 0;
	int ch;
	char buff[BUFFER_SIZE];

	/* count the lines */
	while(!feof(df)) {
		ch = fgetc(df);
		if (ch == '\n') {
			count++;
		}
	}
	rewind(df);

	/* get random word */
	count = rand() % count;
	int row = 1;
	while(row != count) {
		ch = fgetc(df);
		if (ch == '\n') {
			row++;
		}
	}
	fscanf(df, "%s", buff);

	// allocates memory with the length of word in buff + 1
	char *result = malloc(strlen(buff) + 1);

	// convert word to lowercase
	for (int i = 0; i < strlen(buff); i++) {
		buff[i] = (unsigned char) tolower(buff[i]);
	}

	strcpy(result, buff);
    fclose(df);
	
	return result;
}
