#include <stdio.h>
#include "ex1.h"
#include <sys/time.h>

int main(){
	unsigned int stack_bottom = 0;
	stack_bottomvalue = &stack_bottom;
	ARR_SIZE=10;
	initialize();
	char filename[] = "10.txt";
	double time = get_elapsed_time(filename);
	printf("Time Taken for Reading File = %lf ms\n",time);
	
	
	//Time taken by Insertion Sort
	
	struct timeval t1,t2;
	
	gettimeofday(&t1,NULL);
	insertionSort(0);
	gettimeofday(&t2,NULL);
	
	double elapsedTime = (t2.tv_sec-t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec-t1.tv_usec)/1000.0;
	
	printf("Time taken for Insertion Sort = %lf ms\n",elapsedTime);
	printarr();
	
	printf("Stack top = %u\n",stack_topvalue);
	printf("Size bottom = %u\n",stack_bottomvalue);
	printf("Size of Stack = %d\n",abs(stack_topvalue-stack_bottomvalue));
}

