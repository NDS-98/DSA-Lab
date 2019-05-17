#include <stdio.h>
#include <stdlib.h>

int main(){

	char src[20], dest[20];

	printf("Enter source file: ");	
	scanf("%s",src);
	printf("Enter destination file: ");	
	scanf("%s",dest);


	FILE *fptr, *fp_d;
	printf("%s",src);
	fptr = fopen(src,"r");
	fp_d = fopen(dest,"w");
	if(fptr==NULL){
		printf("Error opening file!");
		exit(1);
	}
	if(fp_d==NULL){
		printf("Error!");
		exit(1);
	}
	
	char ch;
	
	while((ch = fgetc(fptr))!=EOF){
		fprintf(fp_d, "%c", ch);
	}
	
	fclose(fptr);
	fclose(fp_d);
	
	return 0;
}
	
	
	
