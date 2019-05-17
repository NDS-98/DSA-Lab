#include "node.h"
#include <stdio.h>
#include <stdlib.h>


NODE* search(char ch, NODE* head)
{
 /* Precodition: head stores the pointer of a node and its definition is as explained in Q1 above. Character ch is to be searched within head and all its siblings.
Postcondition: It returns the address of the node in which ch is present. Otherwise, if head is NULL or ch is not present, it returns NULL.
search function will have binary marking.

 */
	if(head==NULL){
		return NULL;
	}
	
	NODE* temp = head;
	
	while(temp!=NULL){
		if(temp->c==ch){
			return temp;
		}
		temp = temp->sibling;
	}
	
	return NULL;
}
