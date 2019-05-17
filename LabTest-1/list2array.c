#include"node.h"
#include<stdio.h>
#include<stdlib.h>
extern int *Arr[N];
extern int Num_Elements[N];

void ConvertListstoArray(Locality * start)
{
	Locality * temp = start;
	int i=0,j=0;
	while(temp!=NULL){
		Num_Elements[i]=temp->count;
		int *arr = (int *)malloc(sizeof(int)*(temp->count));
		Arr[i] = arr;
		
		Member * temp2 = temp->first;
		j=0;
		while(temp2!=NULL){
			Arr[i][j] = temp2->id;
			temp2 = temp2->next;
			j++;
		}
		i++;
		temp = temp->next;
	}
 
}
