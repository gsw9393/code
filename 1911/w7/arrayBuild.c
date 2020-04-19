#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

void printArray(int **arr);

int main(int argc, char *argv[]) {

    // TODO BELOW
    //  part1: ensure the right number of arguments have been passed in
    // TODO ABOVE

	if (argc!=2){
		printf ("Please enter 1 argument: Your array");
		exit(0);
	}
    // TODO BELOW
    //  part2: ensure the argument we're interested is in of right length
    // TODO ABOVE
	if(strlen(argv[1])!=SIZE*SIZE){
		printf ("Please enter the correct size");
		exit(0);
	}
    // TODO BELOW
    //  part3: malloc your 2D array and populate it
    // TODO ABOVE
	int ** myArray = (int **)malloc(sizeof(int *)*SIZE);
	if (myArray==NULL){
		printf ("malloc error");
		exit(0);
	}
	
	int i,j,k=0;
	for (i=0 ; i<SIZE ; i+=1){
		myArray[i]=(int *)malloc(sizeof(int)*SIZE);
		if (myArray[i]==NULL){
			printf ("malloc error");
			exit(0);
		}
		for (j=0 ; j<SIZE ; j+=1){
			myArray[i][j]=argv[1][k]-'0';
			k++;
		}
	}
	printArray(myArray);
    free(myArray);

    return 0;
}

void printArray(int **arr) {
    int i = 0;
    int j = 0;
    while (i < SIZE) {
        j = 0;
        while (j < SIZE) {
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
