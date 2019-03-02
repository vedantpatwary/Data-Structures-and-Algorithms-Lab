#include "GraphA.h"

Graph createGraph(FILE *fp){
	if(fp ==NULL)
		return NULL;
	
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->listA =(Adjlist)malloc(12*sizeof(struct adjlist));
	g->numV = 12;
	for(int i=0;i<g->numV;i++){
		g->listA[i].head =NULL;
		g->listA[i].data = -1;
	}
	int num1,num2;
	Vertex temp = NULL;
	int flag =0;
	while(fscanf(fp,"%d %d",&num1,&num2) ==2){
		int index1 = hash(num1);
		int index2 = hash(num2);
		g->listA[index1].data = num1;
		g->listA[index2].data = num2;
		temp = createVertex(num2);
		temp->next = g->listA[index1].head;
		g->listA[index1].head = temp;
	}
	return g;
}
	
void printGraph(Graph g){
	Vertex temp = NULL;
	for(int i=0;i<g->numV;i++){
		if(g->listA[i].data ==-1)
			continue;
		printf("%d->",g->listA[i].data);
		temp = getAdj(g,i);
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}	

Vertex getAdj(Graph g,int index){
	return g->listA[index].head;
}


Vertex createVertex(int data){
	Vertex v = (Vertex)malloc(sizeof(struct vertex));
	v->data = data;
	v->next =NULL;
	return v;
}

int hash(int data){
	return data;
}
