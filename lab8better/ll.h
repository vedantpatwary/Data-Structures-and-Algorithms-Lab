#include<stdio.h>
#include<stdlib.h>

typedef struct tree *Tree;

struct list{
	int data;
	struct list *next;
};

typedef struct list *List;

List addL(List l,int data);
void printL(List l);
