#ifndef _LCQUEUE_
#define _LCQUEUE_
//queue structure
typedef struct{
node *front;
node *back;
int elements;
} LCqueue;

//doubly linked nodes
typedef struct node{
node *leading;
node *trailing;
int value;
};

LCqueue *new_queue(void);

//removes first element and returns value
int pop(const LCqueue* q);

//adds value to end of queue
void push(const rLCqueue* q,int x);

//returns number of elements in the queue
int count(const LCqueue* q);

//returns value of first element without removal of the element
int front(const LCqueue* q);

//returns value of last element
int end(const LCqueue* q);

#endif
