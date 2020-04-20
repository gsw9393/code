// COMP1521 19T2 ... lab 1
// cat4: Copy input to output

#include <stdio.h>
#include <stdlib.h>

static void copy (FILE *, FILE *);

int main (int argc, char *argv[])
{
	if (argc==1){
		copy (stdin, stdout);
	}else{
		int i=1;
		while(i<argc){

			FILE *f=fopen(argv[i], "r");

			if (f!=NULL){
				copy(f, stdout);
			}else{
				printf ("Can't read %s",argv[i]);
			}
			i++;
		}
	}
	return EXIT_SUCCESS;
}

// Copy contents of input to output, char-by-char
// Assumes both files open in appropriate mode
static void copy (FILE *input, FILE *output)
{
	char c;
	while((c=fgetc(input))!=EOF){
		fputc(c,output);
	}
		
}
