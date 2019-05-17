#include "que.h"
#include <stdio.h>

int main(){
	struct Queue q = newQ();
	printf("Is the queue empty?\n");
	if(isEmptyQ(q))
		printf("Yes\n");
	else
		printf("No\n");
	
	q = addQ(q,5);
	q = addQ(q,10);
	q = addQ(q,15);
	q = addQ(q,20);
	
	printf("After adding 5,10,15,20 : Length = %d\n",lengthQ(q));
	
	printf("Front element = %d\n",front(q));
	
	q = delQ(q);
	
	printf("After deleting 1 element : Length = %d\n Front Element = %d\n",lengthQ(q),front(q));
	
	printf("The queue looks like:-\n");
	printque(q);
}
