#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "Queue.h"

void initQueue (Queue *q){
    q->nitems=0;
    q->head=0;
    q->tail=0;
}
// insert a new item at the tail of the Queue
void enterQueue (Queue *q, int item){
    q->items[q->tail]=item;
    (q->tail)++;
}
// remove/return the item at the head of the Queue
int leaveQueue (Queue *);
// return the number of items currently in the Queue
int lengthQueue (Queue);
// display the contents of the Queue
void showQueue (Queue);
