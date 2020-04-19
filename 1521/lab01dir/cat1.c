// COMP1521 19T2 ... lab 1
// cat1: Copy input to output

#include <stdio.h>
#include <stdlib.h>

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
	char str[500];
	int ch;
	int i=0;
	while(fscanf(input,"%c",&str[i])!=EOF){
		i++;
	}
	str[i]='\0';

	fprintf(output,"%s",str);
}
