#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct iterator *Iterator;

typedef struct queue *Queue;

struct queue{
	Iterator it[100000000];	
	int front;
	int rear;
	int sizeQueue;
	int count;
};

typedef struct queue *Queue;

Queue createQueue(void);
Queue enque(Queue q,Iterator it);
Queue deque(Queue q);
Iterator front(Queue q);
bool isEmptyQ(Queue q);

