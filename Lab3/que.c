#include "que.h"

#include <stdio.h>
#include <stdlib.h>

struct Queue newQ(){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	// malloc returns a void pointer, but we want pointer of type Queue*, so if we don't type cast, type mismatch will occur!
	q->length = 0;
	q->head = NULL;
	q->tail = NULL;
	return *q;
}

bool isEmptyQ(struct Queue q){
	if(q.length==0)
		return 1;
	else
		return 0;
}

struct Queue delQ(struct Queue q){
	if(q.length==0)
		return q;
	struct Node* temp = q.head;
	q.head = q.head->next;
	q.length--;
	free(temp);
	// Automatic Garbage Collection happens in Java and not in C.
	return q;
}

int front(struct Queue q){
	if(q.length==0){
		printf("Queue is empty!\n");
		return -1;
	}
	return q.head->ele;
}

struct Queue addQ(struct Queue q, int e){
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->ele = e;
	newNode->next = NULL;
	if(q.length==0){
		q.tail = newNode;
		q.head = newNode;
	}
	else{
		q.tail->next = newNode;
		q.tail = newNode;
	}
	q.length++;
	return q;
}

int lengthQ(struct Queue q){
	return q.length;
}

void printque(struct Queue q){
	struct Node * temp = q.head;
	while(temp!=q.tail){
		printf("%d ",temp->ele);
		temp = temp->next;
	}
	printf("%d ",temp->ele);
}
