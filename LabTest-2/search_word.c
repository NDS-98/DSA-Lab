#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern NODE * root;
/*
Precondition: "word" points to the upper-case English word with length > 1.
Post condition: the function returns TRUE if "word" is present in the Trie; FALSE otherwise. Note that global variable "root" stores the root of the Trie data structure.
You have to strictly implement this fun as non-recursive.

*/

boolean search_word(char *word)
{
	NODE* temp = root;
	int i=0;
	int wordlength = strlen(word);
	
	while(temp!=NULL){
		temp = search(word[i],temp->child);
		if(temp==NULL)
			break;
		i++;
		if(i==wordlength && temp->stop_word==TRUE)
			return TRUE;
	}
	return FALSE;
}
