#define MAX_SIZE 100

typedef struct stack Stack;

Stack *stackCreate(void);
void stackPush(Stack *s, int item);
int stackTop(Stack *s);
int stackPop(Stack *s);
int stackSize(Stack *s);
void stackDestroy(Stack *s);
