#include<stdio.h>
#include<stdlib.h>
typedef int Element;
typedef int Key;

struct node Element{
	Key k;
	struct node Element *next;
};

typedef struct node Element *Element;

struct node s{
	int count;
	Element head;
	Element tail;
};

typedef struct node s *SeqList;

SeqList newList();
SeqList insertInOrder(SeqList sl, Element e); 
SeqList insertAtFront(SeqList sl, Element e); 
SeqList insertAtEnd(SeqList sl, Element e);
SeqList deleted(SeqList sl, Element e); 
SeqList deleteAtFront(SeqList sl); 
Element find(SeqList sl, Key k);
void printList(SeqList sl);
