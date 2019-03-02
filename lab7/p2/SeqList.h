#include<stdio.h>
#include<stdlib.h>
typedef int Key;

struct element{
	Key index;
	int count;
	struct element *next;
};

typedef struct element *Element;

struct seqList{
	int count;
	Element head;
	Element tail;
};

typedef struct seqList *SeqList;
typedef struct seqList *Table;

SeqList newList();
SeqList insertInOrder(SeqList sl, Element e); 
SeqList insertAtFront(SeqList sl, Element e); 
SeqList insertAtEnd(SeqList sl, Element e);
int insertAtEndCost(SeqList sl, Element e,int insertionCost);
void deleted(SeqList sl, Element e); 
SeqList deleteAtFront(SeqList sl); 
Element find(SeqList sl,char **Book, Key k);
Element findString(SeqList sl,char **Book,char **strings, Key k);
void printList(SeqList sl,char **Book);
Element newElement(int index);
