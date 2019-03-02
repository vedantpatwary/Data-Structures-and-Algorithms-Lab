#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct vertex{
	char url[2000];
	char name[2000];
	struct vertex *next;
};

typedef struct vertex *Vertex;

struct adjlist{
	bool visited;
	char url[2000];
	char name[2000];
	struct adjlist *next; // for collision
	Vertex head;// for head of its adj
};

typedef struct adjlist *Adjlist;

struct graph{
	int numV;
	Adjlist arr;
};

typedef struct graph *Graph;

Graph createGraph(int m);
Vertex getAdjacent(Graph G,Vertex v);
Graph addEdge(Graph G,Vertex v,Vertex vAdj);
int degree(Graph G,Vertex v);
void DFS(Graph g,Vertex V);
void BFS(Graph g,Vertex V);
Vertex createVertex(char *url,char *name);
void print(Graph g);
int hash(char *s);
void readFile(Graph g,char *url,char *name);
void collisionCount(int *arr);
Adjlist newAdjlistNode(char *url,char *name);
int curl(char *s);
