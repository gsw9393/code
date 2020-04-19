#include <stdio.h>
#include <stdlib.h>

char *copyString(char *str);

int main(int argc, char* argv[]) {
    // TODO BELOW
    //  part 2: need to check if "argc" is correct, and return appropriate message if not
    // TODO ABOVE

    char *argvCopy = copyString(argv[1]);
    printf("String 1: %s\n", argv[1]);
    printf("String 2: %s\n", argvCopy);

    // TODO BELOW
    //  part 3: some code here is missing! That will prevent memory leaks
    // TODO ABOVE
    return 0;
}

char *copyString(char *str) {
    // TODO BELOW
    //  part 1: need to use "malloc" to create new memory of the right size
    //  then use "strcpy" to copy data from string into your new array
    // TODO ABOVE
}
