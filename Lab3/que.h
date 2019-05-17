#include <stdbool.h>

struct Node{
int ele;
struct Node* next;
};

struct Queue{
int length;
struct Node* head;
struct Node* tail;
};

struct Queue newQ();

bool isEmptyQ(struct Queue q);

struct Queue delQ(struct Queue q);

int front(struct Queue q);

struct Queue addQ(struct Queue q, int ele);

int lengthQ(struct Queue q);

void printque(struct Queue q);
