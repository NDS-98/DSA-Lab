#include <stdio.h>
#include <stdlib.h>
#include "multiq.h"
#include <sys/time.h>

struct MultiQ loadData(FILE* f);
struct MultiQ testDel(int num);
double computeTime(struct timeval t1,struct timeval t2);


struct MultiQ mq;

int main(){
	FILE *f = fopen("input10.txt","r");
	struct timeval t1,t2;
	
	gettimeofday(&t1,NULL); //start time
	mq = loadData(f);
	gettimeofday(&t2,NULL); //end time
	
	printf("--------------------------\n");
	printMultiQ(mq);
	printf("Time taken in Loading : %lf ms\n",computeTime(t1,t2));
	
	gettimeofday(&t1,NULL); //start time
	mq = testDel(3);
	gettimeofday(&t2,NULL); //end time
	
	printf("--------------------------\n");
	printf("After deleting 3 elements of highest priority :\n");
	printMultiQ(mq);
	printf("Time taken in Deleting : %lf ms\n",computeTime(t1,t2));
	fclose(f);
}

struct MultiQ loadData(FILE* f){
	mq = createMQ(10);
	
	while(!feof(f)){
		struct Task t;
		fscanf(f,"%d,%d\n",&t.taskId,&t.priority.pvalue);
		mq = addMQ(mq,t);
	}	
	
	return mq;
}

struct MultiQ testDel(int num){
	int i;
	for(i=0;i<num;i++){
		mq = delNextMQ(mq);
	}
	return mq;
}

double computeTime(struct timeval t1,struct timeval t2){
	double elapsedTime = (t2.tv_sec-t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec-t1.tv_usec)/1000.0;
	return elapsedTime;
}
