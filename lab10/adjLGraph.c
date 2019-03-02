#include "adjLGraph.h"
#include "Queue.h"

Graph createGraph(int numV){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->numV = numV;
	g->arr =(Adjlist)malloc(numV*sizeof(struct adjlist));
	for(int i=0;i<numV;i++){
		g->arr[i].data =i;
		g->arr[i].head =NULL;
		g->arr[i].visited = false;
	}
	return g;
}


Vertex getAdjacent(Graph G,Vertex V){
	int index = map(V->data);
	Vertex adj = G->arr[index].head;
	return adj;
}

Graph addEdge(Graph G,Vertex V,Vertex vAdj){
	int index = map(V->data);
	Vertex newV = createVertex(vAdj->data);
	Vertex adj = G->arr[index].head;
	newV->next = adj;
	G->arr[index].head = newV;
	return G;
}

int degree(Graph G,Vertex V){
	int index = map(V->data);
	Vertex adj = G->arr[index].head;
	Vertex temp = adj;
	int count =0;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

Vertex createVertex(int data){
	Vertex v = (Vertex)malloc(sizeof(struct vertex));
	v->data = data;
	v->next =NULL;
	return v;
}

int map(int data){
	return data;
}

void print(Graph g){
	Adjlist arr = g->arr;
	Vertex temp = NULL;
	for(int i=0;i<g->numV;i++){
		printf("%d -> ",i);
		temp = arr[i].head;
		while(temp !=NULL){
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

