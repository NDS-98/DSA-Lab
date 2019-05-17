#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "procedure.h"

//struct Node * head_ls;

int N=20;

int totalHeapSpaceAllocated = 0;

void * myalloc(int space){
	void * start = malloc(space+sizeof(int));
	int * start_addr = (int *)start;
	start_addr[0] = space;
	totalHeapSpaceAllocated+= space;
	return start+sizeof(int);
}

void myfree(void * start_addr){
	totalHeapSpaceAllocated -= *((int*)start_addr-1);
	free(start_addr-sizeof(int));
}

struct Node * createList(int N, struct Node * head){
	srand(time(0));
	
	for(int i=1;i<=N;i++){
		int number = (rand()%(50-1+1))+1;
		
		struct Node * node = (struct Node *)myalloc(sizeof(struct Node));
		node->key = number;
		node->next = NULL;
		
		if(i==1){
			head = node;
		}
		else{
			struct Node * temp = head;
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next = node;
		}
	}
	
	FILE * fp;
	fp = fopen("HeapSize.txt","w");
	fprintf(fp,"Total Heap Space Allocated = %d\n",totalHeapSpaceAllocated);
	fclose(fp);
		
	return head;	
}

struct Node * createCycle(struct Node * head){
	srand(time(0));
	int coin_toss_result = ((rand()%(2-0+1))+0)%2;
	
	//Linear List
	if(coin_toss_result==0){
		return head;
	}
	//Cyclic
	else{
		struct Node * temp = head;
		struct Node * address = NULL;
		int r = (rand()%((N-1)-1+1))+1; // r shouldn't be the last node itself!
		printf("Value of r = %d\n",r);
		int i=1;
		while(temp->next!=NULL){
			if(i==r){
				address = temp;
				printf("-------Found-------%d------\n",i);
			}
			temp = temp->next;
			i++;
		}
		temp->next = address;
		return head;
	}
}

struct Node * makeCircularList(struct Node* head){
	if(testCyclic(head)){
		struct Node * temp = head;
		int i=1;
		while(i<=N){
			temp = temp->next;
			i++;
		}
		struct Node * addr = temp;
		
		while(head!=addr){
			temp = head;
			head = head->next;
			myfree(temp);  // Since each node was created individually, 							hence has to be freed individually.
		}
	}
	else{
		struct Node* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = head;
	}
	return head;

}


