#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct vertex{
	int data;
	//int index;
	bool visited;
};

typedef struct vertex *Vertex;

struct enumeration{
	Vertex v;
	struct enumeration *next;
};

typedef struct enumeration *Enumeration;

struct graph{
	int numV;
	int **adjM;
	Vertex listV;
};

typedef struct graph *Graph;

Graph createGraph(int numV);
Enumeration getAdjacent(Graph G,Vertex v);
Graph addEdge(Graph G,Vertex v,Vertex vAdj);
int degree(Graph G,Vertex v);
int map(int data);
//Vertex createVertex(int data);
void DFS(Graph g,Vertex v);
void BFS(Graph g,Vertex v);
void printAdjM(Graph g);
