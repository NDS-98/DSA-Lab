#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "procedure.h"

int main(){
	struct Node * ls;
	int N = 20;
	ls = createList(N,ls);
	
	struct Node * temp = ls;
	
	while(temp!=NULL){
		printf("%d \n",temp->key);
		temp = temp->next;
	}
	
	ls = createCycle(ls);
	
	bool cyclic = testCyclic(ls); // On passing the pointer ls, whatever change is 						made to the contents in the fn testCyclic, would 				be reflected in original ls(coz of access through pointers).
	
	// Hence we don't use Link Reversal Method for testing cyclic coz it distorts 			the original ls.
	
	if(cyclic==0)
		printf("Linear\n");
	else
		printf("Cyclic\n");
		
	ls = makeCircularList(ls);
	
	int i;
	temp = ls;
	printf("-------------FINAL LL------------\n");
	for(i=1;i<=20;i++){
		printf("%d\n",temp->key);
		temp = temp->next;
	}
	printf("%d ----Hence Cyclic----\n",temp->key);
		
	return 0;
}
