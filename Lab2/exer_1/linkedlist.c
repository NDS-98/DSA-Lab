#include "linkedlist.h"

void insertFirst(struct linkedList *head, int ele){
	// create a node
	struct node * link = (struct node *) malloc (sizeof(struct node));
	link->element = ele;
	link->next  = head->first;
	head->first = link;
	head->count++;
}

// Delete First Item
struct node * deleteFirst(struct linkedList *head){
	if(head->first==NULL){
		printf("The list is empty!");
	}
	else{
		head->first = head->first->next;
	}
	return head->first;
}

// Display the list
void printList(struct linkedList *head){
	struct node *ptr = head->first;
	printf("\n[ ");
	
	// Start fro beginning
	while(ptr!=NULL){
		printf("%d, ",ptr->element);
		ptr = ptr->next;
	}
	
	printf(" ]");
}
