#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct vertex{
	int data;
	struct vertex *next;
};

typedef struct vertex *Vertex;

struct adjlist{
	bool visited;
	int data;
	Vertex head;
};

typedef struct adjlist *Adjlist;

struct graph{
	int numV;
	Adjlist arr;
};

typedef struct graph *Graph;

Graph createGraph(int numV);
Vertex getAdjacent(Graph G,Vertex v);
Graph addEdge(Graph G,Vertex v,Vertex vAdj);
int degree(Graph G,Vertex v);
int map(int data);
void DFS(Graph g,Vertex V);
void BFS(Graph g,Vertex V);
Vertex createVertex(int data);
void print(Graph g);
