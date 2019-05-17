#include <stdlib.h>
#include <string.h>
#include "dns.h"

void readData(int n,FILE *fp){
	
	while(n--){
		char *name = (char*)malloc(sizeof(char)*100);
		char *IP = (char*)malloc(sizeof(char)*20);
		fscanf(fp,"%[^ ] %s \n",name,IP);
		
		//IP Node
		Node *IPNode = (Node*)malloc(sizeof(Node));
		IPNode->key = IP;

		name = strrev(name);
		
		char *token = strtok(name,".");
		Node *temp = root;
		int i;
		while(token!=NULL){
			token = strrev(token);
			
			int f=0;
			for(i=0;i<temp->children;i++){
				if(strcmp(temp->child[i]->key,token)==0){
					temp = temp->child[i];
					f=1;
					break;
				}
			}
			
			if(f==0){
				break;
			}
			
			token = strtok(NULL,".");
			
		}
		
		if(token!=NULL)
			token = strrev(token);

		int c=0;
		while(token!=NULL){
			token = strrev(token);
			c++;
			Node* newNode = (Node*) malloc(sizeof(Node));
			newNode->children = 0;
			newNode->key = token;
			newNode->child = (Node**)malloc(sizeof(Node *)*10);
			if(c==1){
				temp->child[i] = newNode;
				temp->children++;
				temp = temp->child[i];
			}
			else{
				temp->child[0] = newNode;
				temp->children++;
				temp = temp->child[0];
			}
			token = strtok(NULL,".");
		}

		temp->child[temp->children++] = IPNode;
	}
}

void lookup(char *name){
	char *copy = (char*)malloc(sizeof(char)*strlen(name));
	strcpy(copy,name);
	
	int noOfTokens=0;

	// Counting the no. of tokens
	char *t = strtok(copy,".");
	while(t!=NULL){
		noOfTokens++;
		t = strtok(NULL,".");
	}

	name = strrev(name);

	char *token = strtok(name,".");
	Node *temp = root;

	int *position = (int *)malloc(sizeof(int)*10);
	int p=0;

	while(token!=NULL){
		token = strrev(token);
		for(int i=0;i<temp->children;i++){
			if(strcmp(token,temp->child[i]->key)==0){
				temp = temp->child[i];
				position[p] = i;
				p++;
				break;
			}
		}
		if(p==0){
			printf("Domain Name Not Found!\n");
			return;
		}
		if(p==noOfTokens){
			for(int j=0;j<temp->children;j++)
				printf("IP : %s\n",temp->child[j]->key);
			return;
		}
		token = strtok(NULL,".");
	}

	printf("Child Numbers : ");
	
	for(int i=0;i<p;i++){
		printf("%d ",position[i]);
	}
	printf("\n");
}

char* strrev(char* str){
	if(!str || !(*str))
		return str;
	
	int i = strlen(str)-1;
	int j = 0;
	char ch;
	char *reverse = (char*)malloc(sizeof(char)*strlen(str));

	while(i>=0){
		reverse[j] = str[i];
		i--;
		j++;	
	}
	return reverse;
}


