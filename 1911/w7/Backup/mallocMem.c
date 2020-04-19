#include <stdio.h>
#include <stdlib.h>

int *createInteger(int value);
double *createDouble(double value);

int main(int argc, char* argv[]) {

    int *heapInteger = createInteger(3);
    double *heapDouble = createDouble(4.0);

    printf("heapInteger: %d\n", *heapInteger);
    printf("heapDouble: %lf\n", *heapDouble);

    // TODO BELOW
    //  part 3: don't forget to free your memory and set their values
    //          to NULL
    // TODO ABOVE
    return 0;
}

// TODO BELOW
//  part 1: Complete the "createInteger" function that uses
//          malloc to store a new integer on the heap
int *createInteger(int value) {
    return NULL; // You don't want to return null
}
// TODO ABOVE

// TODO BELOW
//  part 2: Complete the "createDouble" function that uses
//          malloc to store a new integer on the heap
double *createDouble(int value) {
    return NULL; // You don't want to return null
}
// TODO ABOVE
