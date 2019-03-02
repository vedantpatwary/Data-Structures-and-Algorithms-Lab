#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define HEAD 0
#define TAIL 1
extern int count;

struct list{
	int n;
	struct list *next;
};
typedef struct list *List;

void myfree(void *p);
void printAdd(int *p);
void* myalloc(int x);
List createList(int N);
void printList(List l);
List createCycle(List l);
