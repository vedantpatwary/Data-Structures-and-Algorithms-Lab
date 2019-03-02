#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#ifndef NEW_ELE
struct Element{
	int key;
};
typedef struct Element Element;

struct node {
	Element ele;
	struct node *next;
};

typedef struct node *node;
struct q{
	node head;	
	node tail;
	int count;
};

typedef struct q *Queue;

#endif

Element front(Queue q); // returns the element from the front of the Queue;
Queue newQ(); // returns an empty Queue
bool isEmptyQ(Queue q); // tests whether q is empty
Queue delQ(Queue q); // deletes the element from the front of the Queue;eue
Queue addQ(Queue q , Element e); 
int lengthQ(Queue q); // returns the length of the Queue
Element newE(int x);
void printQ(Queue q);



