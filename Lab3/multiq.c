#include <stdio.h>
#include <stdlib.h>
#include "multiq.h"

struct MultiQ createMQ(int num){
	struct MultiQ* mq = (struct MultiQ*)malloc(sizeof(struct MultiQ));
	
	mq->qlist = (struct Queue*)malloc(sizeof(num));
	
	//mq->qlist = (struct Queue*)malloc(sizeof(int)*num); //Also works fine
	for(int i=0;i<num;i++){
		mq->qlist[i] = newQ();
	}
	mq->length = num;
	return *mq;
}

struct MultiQ addMQ(struct MultiQ mq, struct Task t){
	int p = t.priority.pvalue-1;
	mq.qlist[p] = addQ(mq.qlist[p],t.taskId);
	return mq;
}

struct Task nextMQ(struct MultiQ mq){
	int i = mq.length-1;
	while(isEmptyQ(mq.qlist[i])){
		i--;
	}
	struct Task t;
	t.taskId = front(mq.qlist[i]);
	t.priority.pvalue = i+1;
	return t;
}

struct MultiQ delNextMQ(struct MultiQ mq){
	if(isEmptyMQ(mq)){
		printf("No element to delete!\n");
		return mq;
	}
	int i = mq.length-1;
	while(isEmptyQ(mq.qlist[i])){
		i--;
	}
	mq.qlist[i] = delQ(mq.qlist[i]);
	return mq;
}

bool isEmptyMQ(struct MultiQ mq){
	int i;
	for(i=0;i<mq.length;i++){
		if(!isEmptyQ(mq.qlist[i]))
			return 0;
	}
	return 1;
}

int sizeMQ(struct MultiQ mq){
	return mq.length;
}

int sizeMQbyPriority(struct MultiQ mq, Priority p){
	int i = p.pvalue-1;
	return mq.qlist[i].length;
}

struct Queue getQueueFromMQ(struct MultiQ mq, Priority p){
	return mq.qlist[p.pvalue-1];
}

void printMultiQ(struct MultiQ mq){
	int i;
	for(i=0;i<mq.length;i++){
		printf("Queue %d : ",i+1);
		if(!isEmptyQ(mq.qlist[i]))
			printque(mq.qlist[i]);
		else
			printf("EMPTY");
		printf("\n");
	}
}
