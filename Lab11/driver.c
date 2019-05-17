#include <stdio.h>
#include <stdlib.h>
#include "dns.h"

int main(){
	Node *rootNode = (Node*)malloc(sizeof(Node));
	rootNode->key = NULL;
	rootNode->children = 0;
	rootNode->child = (Node**)malloc(sizeof(Node*)*10);

	//Initializing global variable root
	root = rootNode;

	FILE *fp = fopen("input.txt","r");
	int value,n;
	char *name;

	while(!feof(fp)){
		fscanf(fp,"%d ",&value);

		if(value==1){
			fscanf(fp,"%d",&n);
			readData(n,fp);
		}
		else if(value==2){
			fscanf(fp,"%s",name);
			lookup(name);
		}
		else{
			printf("Program Stopped!\n");
			break;
		}
	}

	return 0;
}

