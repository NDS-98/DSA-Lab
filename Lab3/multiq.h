#include <stdbool.h>
#include "que.h"

struct MultiQ{
struct Queue* qlist;
int length;
};

typedef struct{
int pvalue;
} Priority;

struct Task{
int taskId;
Priority priority;
};


struct MultiQ createMQ(int num);

struct MultiQ addMQ(struct MultiQ mq, struct Task t);

struct Task nextMQ(struct MultiQ mq);

struct MultiQ delNextMQ(struct MultiQ mq);

bool isEmptyMQ(struct MultiQ mq);

int sizeMQ(struct MultiQ mq);

int sizeMQbyPriority(struct MultiQ mq, Priority p);

struct Queue getQueueFromMQ(struct MultiQ mq, Priority p); 

void printMultiQ(struct MultiQ mq);
