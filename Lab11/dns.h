#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;

struct node{
	char *key;
	int children;
	Node **child;
};

Node * root;

void readData(int n,FILE* fp);

void lookup(char *name);

char *strrev(char* str);
