/* File: test.c */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	printf("%s\n",argv[0]);
	for(int i=1;i<argc;i++)
		printf("%d\n",atoi(argv[i]));
	}
