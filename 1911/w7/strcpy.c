#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copyString(char *str,int length);

int main(int argc, char* argv[]) {
    // TODO BELOW
    //  part 2: need to check if "argc" is correct, and return appropriate message if not
    // TODO ABOVE
    if (argc!=2){
        printf ("not enough arguments, please enter you string\n");
        exit(1);
    }

    char *argvCopy = copyString(argv[1],sizeof(argv[1]));
    printf("String 1: %s\n", argv[1]);
    printf("String 2: %s\n", argvCopy);

    free(argvCopy);
    argvCopy=NULL;
    // TODO BELOW
    //  part 3: some code here is missing! That will prevent memory leaks
    // TODO ABOVE
    return 0;
}

char *copyString(char *str, int length) {
    // TODO BELOW
    //  part 1: need to use "malloc" to create new memory of the right size
    //  then use "strcpy" to copy data from string into your new array
    // TODO ABOVE
    char *p=(char *)malloc(sizeof(char)*(length+1));
    if (p==NULL){
        printf ("malloc error");
        exit(1);
    }
    strcpy(p,str);
    return p;
}
