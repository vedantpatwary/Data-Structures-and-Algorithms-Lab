#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct vertex *Vertex;

struct node{
	Vertex v;
	struct node *next;
};

typedef struct node *Node;

struct queue{
	Node head;
	Node tail;
	int count;
};

typedef struct queue *Queue;

Queue createQ(void);
Vertex front(Queue q);
Queue enque(Queue q,Vertex v);
Queue deque(Queue q);
bool isEmptyQ(Queue q);

