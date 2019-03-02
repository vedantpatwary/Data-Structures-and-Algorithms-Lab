#include "adjLGraph.h"

int main(void){
	Vertex v0 = createVertex(0);
	Vertex v1 = createVertex(1);
	Vertex v2 = createVertex(2);
	Vertex v3 = createVertex(3);
	Vertex v4 = createVertex(4);
	Vertex v5 = createVertex(5);
	Graph g = createGraph(6);
	g = addEdge(g,v0,v2);
	g = addEdge(g,v1,v3);
	g = addEdge(g,v0,v1);
	g = addEdge(g,v3,v4);
	g = addEdge(g,v3,v2);
	g = addEdge(g,v4,v5);
	print(g);
	printf("\n DFS:");
	//DFS(g,v0);
	printf("\n BFS:");
	BFS(g,v0);
	return 0;
}
	
	
