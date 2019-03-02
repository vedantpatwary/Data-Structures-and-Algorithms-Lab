#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tree *Tree;

typedef Tree Element;

struct iterator{
	Element head;
	int cur;
	int size;
};

typedef struct iterator *Iterator;

bool hasMoreElements(Iterator it);
Element getNextElement(Iterator it);
