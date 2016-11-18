#include <stdlib.h>
#include "LCqueue.h"



//simplified doubly linked-list queue
//for some reason available queue libraries wouldn't work on the teensy.

//instantiates a memory location with a new queue. takes a single value to instantiate as the first node
LCqueue *new_queue(void){
	LCqueue *temp = (LCqueue *)malloc(sizeof(LCqueue));
	temp->front = NULL;
	temp->back = NULL;
	temp->elements = 0;
	return temp;  		
}

node *new_node(int x){
	node *temp = (node *)malloc(sizeof(node));
	temp->leading = NULL;
	temp->trailing = NULL;
	temp->value = x;
	return temp;
}

int pop(LCqueue* q){
	int temp;
	node *tempNode;
	if(q->elements == 0){
		return -1;
	}
	else{		
		//decrements # of elements
		q->elements = q->elements - 1;
		
		//pulls the value of the front node
		temp = q->front->value;
		
		//pulls the pointer to the next node from the front
		tempNode = q->front->trailing;
		
		if(tempNode != NULL){
		//clears the leading pointer on the next node 
		tempNode->leading = NULL;
		}

		//deallocates the memory from the "front" node. 
		free(q->front);

		//sets the new front node
		q->front = tempNode;
		
		return temp;
	}		
}

void push(LCqueue* q, int x){
	//allocating memory
        node *temp = new_node(x); 

	//linking all necessary links
	if(q->back == NULL && q->front == NULL){
		//from empty queue
		q->back = temp;
		q->front = temp;
	}
	else{
		//linking 
		q->back->trailing = temp;
		temp->leading = q->back;
		q->back = temp;
	}
	//incrementing "elements" count
	q->elements = q->elements + 1; 
}

int count(const LCqueue* q){
	return q->elements;
}

int front(const LCqueue* q){
	return q->front->value;
 }


int end(const LCqueue* q){
	return q->back->value;
}

int test(LCqueue *q){
	
}

