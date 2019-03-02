#include<stdio.h>
#include<stdlib.h>


typedef int Vertex;

struct edge{
	Vertex head;
	Vertex tail;
};

typedef struct edge *Edge;

struct graph{
	int numE;
	Edge listE;
};

typedef struct graph *Graph;

Graph createGraph(FILE *fp);
void printGraph(Graph g);
