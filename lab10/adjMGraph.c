#include "adjMGraph.h"

Graph createGraph(int numV){
	Graph G = (Graph)malloc(sizeof(struct graph));
	G->numV = numV;
	G->adjM = (int **)malloc(sizeof(int*)*numV);
	for(int i=0;i<G->numV;i++)
		G->adjM[i] = (int*)malloc(sizeof(int)*numV);

	G->listV = (Vertex)malloc(sizeof(struct vertex)*numV);

	for(int i=0;i<numV;i++){
		G->listV[i].data =i;
		G->listV[i].visited = false;
	}	

	for(int i=0;i<numV;i++)
		for(int j=0;j<numV;j++)
			G->adjM[i][j] =0;
	
	return G;
}
			
Enumeration getAdjacent(Graph G,Vertex v){
	int **p = G->adjM;
	int index = map(v->data);
	Enumeration prevE = NULL;
	Enumeration nextE = NULL;
	Enumeration head  = NULL;
	int count =0;
	for(int j=0;j<G->numV;j++){
		if(p[index][j] ==1){
			prevE = nextE;
			nextE = (Enumeration)malloc(sizeof(struct enumeration));
			nextE->v = &G->listV[j];
			nextE->next =NULL;

			if(count ==0)
				head = nextE;
			else
				prevE->next = nextE;

			count++;
		}
	}
	return head;
}
				
Graph addEdge(Graph G,Vertex v,Vertex vAdj){
	int **p = G->adjM;
	int index1 = map(v->data);
	int index2 = map(vAdj->data);
	p[index1][index2] = 1;
	return G;
}

int degree(Graph G,Vertex v){
	int index = map(v->data);
	int **p = G->adjM;
	int count =0;
	for(int j=0;j<G->numV;j++)
		if(p[index][j] ==1)
			count++;
	return count;
}

/*
Vertex createVertex(int data){
	Vertex v = (Vertex)malloc(sizeof(struct vertex));
	v->data = data;
	v->visited = false;
	return v;
}
*/
int map(int data){//maps vertex data to index
	return data;
}

void printAdjM(Graph g){

	for(int i=0;i<g->numV;i++){
		for(int j=0;j<g->numV;j++)
			printf("%d ",g->adjM[i][j]);
		printf("\n");
	}
}

