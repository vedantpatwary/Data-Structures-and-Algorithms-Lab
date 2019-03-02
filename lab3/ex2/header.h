#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;

struct list{
	int n;
	struct list *next;
};
typedef struct list *List;

void myfree(void *p);
void printAdd(int *p);
void* myalloc(int x);

