#include <stdlib.h>
#include <LCqueue.h>
//simplified doubly linked-list queue
//for some reason available queue libraries wouldn't work on the teensy.

//instantiates a memory location with a new queue. takes a single value to instantiate as the first node
LCqueue *new_queue(void);
	struct LCqueue *temp = malloc(sizeof(struct LCqueue));
	temp->front = NULL;
	temp->back = NULL;
	temp->elements = NULL;
	return temp;  		
}

int pop(const LCqueue* q){
	int temp;
	struct node *tempnode;
	if(q.elements == 0){
		return NULL;
	}
	else{		
		//decrements # of elements
		q.elements = q.elements - 1;
		
		//pulls the value of the front node
		temp = q->front.value;
		
		//pulls the pointer to the next node from the front
		tempNode = q->front.trailing;
		
		if(tempNode != NULL){
		//clears the leading pointer on the next node 
		tempNode->leading = NULL;
				
		//deallocates the memory from the "front" node. 
		free(q->front);

		//sets the new front node
		q.front = tempNode;
		
		return temp;
		}
		
	}		
}

void push(const LCqueue* q, int x){
	//allocating memory
	struct node *temp = malloc(sizeof(struct node));
	*temp =  struct node real; 
	temp->value = x;

	//linking all necessary links
	
	//linking forward
	temp->leading = q->back;

	//linking backwards
	q->back.trailing = temp;
	q.back = temp;

	//incrementing "elements" count
	q->elements = q->elements + 1; 
}

int count(const LCqueue* q){
	return q->elements;
}

int end(const LCqueue* q){
	return q->front.value;
}

int end(const LCqueue* q){
	return q->back.value;
}
 
