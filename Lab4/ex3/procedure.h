#include <stdio.h>
#include <stdbool.h>

struct Node{
	int key;
	struct Node * next;
};

void * myalloc(int space);

void myfree(void * start_addr);

struct Node * createList(int N, struct Node * head);

struct Node * createCycle(struct Node * head);

bool testCyclic(struct Node * head);

struct Node * makeCircularList(struct Node* head);
