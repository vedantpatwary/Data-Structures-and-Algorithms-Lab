#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define NEW_ELE
typedef int Priority;
struct Element{
	int tid;
	Priority p;
};
typedef struct Element Element;
typedef Element Task;

struct node {
	Task ele;
	struct node *next;
};
typedef struct node *node;

struct q{
	node tail; 
	node head;
	int count;
	int p;
};

typedef struct q *Queue;
struct multiq{
	int size;
	Queue q;
};
typedef struct multiq *MultiQ;
Task newT(Priority p,int tid);
MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t); // adds t to the Queue corresponding to
Task nextMQ(MultiQ mq); // returns the front of the non-empty Queue in 
MultiQ delNextMQ(MultiQ mq); // deletes the front of the non-empty Queue in
bool isEmptyMQ(MultiQ mq); // tests whether all the Queues in mq a
int sizeMQ(MultiQ mq); // returns the total number of items in the MultiQ
int sizeMQbyPriority(MultiQ mq, Priority p); 
Queue getQueueFromMQ(MultiQ, Priority p);
void printMultiQ(MultiQ mq); 



