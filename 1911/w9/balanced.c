#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

int main (void){

	int i,c,test = 0;

	Stack *stack1=stackCreate();

	c=getchar();
	for (i=0; c!=EOF&&i<MAX_SIZE; i++){
		if(c=='('||c=='{'||c=='['){
			stackPush(stack1,c);
			test++;
		}else if(c==')'||c=='}'||c==']'){
			stackPush(stack1,c);
			test--;
		}
		c=getchar();
	}
	if(test==0){
		printf ("Yes, balanced.\n");
	}else{
		printf ("No, not balanced.\n");
	}
    stackDestroy(stack1);
	return 0;
}
