#include "adjMGraph.h"

int main(void){
	Graph g = createGraph(6);

	Vertex v0 = &g->listV[0];
	Vertex v1 = &g->listV[1];
	Vertex v2 = &g->listV[2];
	Vertex v3 = &g->listV[3];
	Vertex v4 = &g->listV[4];
	Vertex v5 = &g->listV[5];

	g = addEdge(g,v0,v1);
	g = addEdge(g,v1,v3);
	g = addEdge(g,v0,v2);
	g = addEdge(g,v3,v2);
	g = addEdge(g,v3,v4);
	g = addEdge(g,v4,v5);

	printAdjM(g);
	printf("DFS:\n");
	//DFS(g,v0);
	printf("\nBFS:");
	BFS(g,v0);
	return 0;
}
	
	
