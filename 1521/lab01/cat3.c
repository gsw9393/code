// COMP1521 19T2 ... lab 1
// cat3: Copy input to output

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void copy (FILE *, FILE *);

int main (int argc, char *argv[])
{
	copy (stdin, stdout);
	return EXIT_SUCCESS;
}
// Copy contents of input to output, char-by-char
// Assumes both files open in appropriate mode
static void copy (FILE *input, FILE *output)
{
	char s[BUFSIZ];
	while(strlen(fgets(s,BUFSIZ,input))>1){
		printf ("string length = %d\n",strlen(s));
		fputs(s,output);
	}

}
