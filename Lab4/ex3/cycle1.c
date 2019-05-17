#include <stdio.h>
#include "procedure.h"
#include <stdbool.h>


// Hare-and-Tortoise algorithm

bool testCyclic(struct Node * head){

	if(head==NULL){
		printf("List is Empty!\n");
		return 0;
	}
	
	struct Node * hare = head;
	struct Node * tort = head;
	
	int f=0;

	while(hare!=NULL && hare->next!=NULL){
		tort = tort->next;
		hare = hare->next->next;
		if(hare!=NULL && (hare->next==tort || hare==tort)){
			f=1;
			break;
		}
	}
	
	if(f==1)
		return 1;
	else
		return 0;
}
