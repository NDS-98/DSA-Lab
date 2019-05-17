#include <stdio.h>
#include <stdbool.h>
#include "procedure.h"

// Link-Reversal Algorithm

bool testCyclic(struct Node * head){
	struct Node* right = NULL;
	struct Node* left = head;
	struct Node* temp = left->next;
	left->next = NULL;
	int f=0;
	while(temp!=NULL){
		right = temp->next;
		temp->next = left;
		left = temp;
		temp = right;
		if(right==head){
			f=1;
			break;
		}
	}
	if(f==1)
		return 1;
	else
		return 0;
}
