#ifndef _LCQUEUE_H_
#define _LCQUEUE_H_
//queue structure

//doubly linked nodes
typedef struct node{
 struct node *leading;
 struct node *trailing;
 int value;
};

typedef struct LCqueue{
 struct node *front;
 struct  node *back;
 int elements;
} LCqueue;

LCqueue *new_queue(void);

//removes first element and returns value
int pop(LCqueue* q);

//adds value to end of queue
void push(LCqueue* q,int x);

//returns number of elements in the queue
int count(const LCqueue* q);

//returns value of first element without removal of the element
int front(const LCqueue* q);

//returns value of last element
int end(const LCqueue* q);

#endif
