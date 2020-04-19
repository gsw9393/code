#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copyString(char *str);

int main(int argc, char* argv[]) {
    // TODO BELOW
    //  part 2: need to check if "argc" is correct, and return appropriate message if not
    // TODO ABOVE

    if (argc!=2){
        printf("Please enter 1 argument: your string\n");
        exit(0);
    }
  

    char *argvCopy = copyString(argv[1]);
    printf("String 1: %s\n", argv[1]);
    printf("String 2: %s\n", argvCopy);

    // TODO BELOW
    //  part 3: some code here is missing! That will prevent memory leaks
    // TODO ABOVE
    free(argvCopy);
    argvCopy=NULL;
    return 0;
}

char *copyString(char *str) {
    int length = strlen(str);

    char *newStr = (char *)malloc(sizeof(char)*length+1);
    if (newStr==NULL){
        printf("malloc error\n");
        exit(1);
    }
    strcpy(newStr,str);
    return newStr;
    

    // TODO BELOW
    //  part 1: need to use "malloc" to create new memory of the right size
    //  then use "strcpy" to copy data from string into your new array
    // TODO ABOVE
}
