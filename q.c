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
    assert(q->nitems < MAXQ);
    if (q->nitems!=0){//checks if tail is end of array
        q->tail=(q->tail+1)%MAXQ;//if end of 
    }
    q->items[q->tail]=item;
    q->nitems++;
}
// remove/return the item at the head of the Queue
int leaveQueue (Queue *q){
    assert(q->nitems > 0);
    if (q->nitems!=0){
        int temp = q->items[q->head];
        q->head = (q->head + 1) % MAXQ;
        q->nitems--;
        return temp;
    }
}
// return the number of items currently in the Queue
int lengthQueue (Queue q){
    return q.nitems;
}

// display the contents of the Queue
void showQueue (Queue q){
    int i;
    printf ("H");
    i= q.head;
    for (int n=0 ; n < q.items ; n+=1){
        printf(" %d", q.items[i]);
        i = (i + 1) % MAXQ;
    }
    printf(" T");
    printf("   h=%d, t=%d, n=%d\n", q.head, q.tail, q.nitems);
}
