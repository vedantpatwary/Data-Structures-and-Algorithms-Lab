#include<stdio.h>
#include<stdlib.h>

struct vertex{
	int data;
	struct vertex *next;
};

typedef struct vertex *Vertex;

struct adjlist{
	int data;
	Vertex head;
};

typedef struct adjlist *Adjlist;

struct graph{
	Adjlist listA;
	int numV;
};

typedef struct graph *Graph;

Graph createGraph(FILE *fp);
Vertex createVertex(int data);
void printGraph(Graph g);
Vertex getAdj(Graph g,int index);
int hash(int data);
