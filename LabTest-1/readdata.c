#include"node.h"
#include<stdio.h>
#include<stdlib.h>

//2016B4A70891P

Locality * ReadFileintoLists(char *filename)
{
	FILE *fp = fopen(filename,"r");
	
	if(fp==NULL){
		printf("File Not Found\n");
		return NULL;
	}
	
	Locality * loclist = (Locality*)malloc(sizeof(Locality)*N);
	
	int i=1;
	while(!feof(fp)){
		int loc;
		int id;
		fscanf(fp,"%d",&loc);
		
		Locality * locality = (Locality*)malloc(sizeof(Locality));
		locality->count=loc;
		locality->next = NULL;
		
		if(i==1){
			loclist = locality;
		}
		else{
			Locality * temp = loclist;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = locality;
		}
		
		
		while(loc--){
			fscanf(fp,",%d",&id);
			Member * member = (Member*)malloc(sizeof(Member));
			member->id = id;
			member->next = NULL;
			
			if(locality->first==NULL){
				locality->first = member;
			}
			else{
				Member * temp = locality->first;
				while(temp->next!=NULL){
					temp = temp->next;
				}
				temp->next = member;
			}
		}
		fscanf(fp,"\n");
		i++;
	}
	fclose(fp);
	return loclist;
}

void PrintLists(Locality *start)
{
	Locality *temp = start;
	while(temp!=NULL){
		printf("%d",temp->count);
		
		Member * temp2 = temp->first;
		while(temp2!=NULL){
			printf(",%d",temp2->id);
			temp2 = temp2->next;
		}
		printf("\n");
		temp = temp->next;
	}
}
