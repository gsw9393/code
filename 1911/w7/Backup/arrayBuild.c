#include <stdio.h>

#define SIZE 3

void printArray(int **arr);

int main(int argc, char *argv[]) {

    // TODO BELOW
    //  part1: ensure the right number of arguments have been passed in
    // TODO ABOVE

    // TODO BELOW
    //  part2: ensure the argument we're interested is in of right length
    // TODO ABOVE

    // TODO BELOW
    //  part3: malloc your 2D array and populate it
    // TODO ABOVE

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
