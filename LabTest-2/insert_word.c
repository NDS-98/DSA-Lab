#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Precondition: "word" points to the upper-case English word with length > 1.
Post condition: The function inserts each character of "word" in Trie appropriately. Note that global variable "root" stores the root of the Trie datastructure.
You have to strictly implement this function as non-recursive.

*/

void insert_word(char *word)
{
	NODE* temp = root;
	
	int wordlength = strlen(word);
	
	NODE* temp1; //To keep track of parent of temp
	
	int i=0;
	while(temp!=NULL){
		temp1 = temp;
		temp = search(word[i],temp->child);
		if(temp==NULL)
			break;
		i++;
		if(i==wordlength){
			temp->stop_word = TRUE;
			return;
		}
		
	}
	while(i<wordlength){
		NODE* new_node = (NODE*)malloc(sizeof(NODE));
		new_node->c = word[i];
		new_node->child = NULL;
		new_node->sibling = NULL;
		new_node->stop_word = FALSE;
		
		insert(&(temp1->child),new_node);
		temp1 = search(word[i],temp1->child);
		i++;
	}
	temp1->stop_word = TRUE;
	
}
