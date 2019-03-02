#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tree *Tree;

struct node{
	Tree t;
	struct node *next;
};

typedef struct node *Node;

struct queue{
	Node head;
	Node tail;
	int count;
};

typedef struct queue *Queue;

Queue createQueue(void);
Queue enque(Queue q,Tree t);
Queue deque(Queue q);
bool isEmptyQ(Queue q);
Tree front(Queue q);
bool isEmptyQ(Queue q);
