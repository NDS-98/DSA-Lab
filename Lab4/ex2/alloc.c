#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int totalSpaceAllocated=0;

void * myalloc(int space){
	void * start = malloc(space+sizeof(int));
	int * start_addr = (int *)start;
	start_addr[0] = space;
	totalSpaceAllocated+= space;
	return start+sizeof(int);
}

void myfree(void * start_addr){
	totalSpaceAllocated -= *((int*)start_addr-1);
	free(start_addr-sizeof(int));
}

int main(){
	srand(time(0));
	
	for(int i=1;i<=5;i++){
		int M = (rand()%(25000-10000+1))+10000;
		int * arr = (int *)myalloc(M*sizeof(int));
		printf("First Address - %u \n",&arr);
		printf("Last Address - %u \n",&arr[M-1]);
		printf("Total Space Allocated by you = %d\n",totalSpaceAllocated);
		printf("M = %d\n",M);
		myfree(arr);
		printf("Total Space Allocated by you after free = %d\n",totalSpaceAllocated);
	}
	return 0;
}
