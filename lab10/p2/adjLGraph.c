#include "adjLGraph.h"
#include "Queue.h"

Graph createGraph(int m){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->numV = 0;
	g->arr =(Adjlist)malloc(m*sizeof(struct adjlist));
	for(int i=0;i<m;i++){
		strcpy(g->arr[i].name,"\0");
		strcpy(g->arr[i].url,"\0");
		g->arr[i].head =NULL;
		g->arr[i].next = NULL;
		g->arr[i].visited = false;
	}
	return g;
}


Vertex getAdjacent(Graph G,Vertex V){
	int index = hash(V->url);
	Adjlist temp = &G->arr[index];
	while(temp !=NULL){
		if(strcmp(temp->url,V->url)==0){
			return temp->head;
		}
		temp = temp->next;
	}
	return NULL;
}

int degree(Graph G,Vertex V){
	int index = hash(V->url);
	Vertex adj = G->arr[index].head;
	Vertex temp = adj;
	int count =0;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

Vertex createVertex(char *url,char *name){
	Vertex v = (Vertex)malloc(sizeof(struct vertex));
	strcpy(v->url,url);
	strcpy(v->name,name);
	v->next =NULL;
	return v;
}

void print(Graph g){
	int m = 211;
	Adjlist arr = g->arr;
	Vertex temp = NULL;
	for(int i=0;i<m;i++){
		printf("arr[%d]:",i);
		printf("%s: ",g->arr[i].url);
	//	temp = arr[i].head;
	//	while(temp !=NULL){
	//		printf("%s->",temp->url);
	//		temp = temp->next;
	//	}
		printf("\n");
	}
}

Graph addEdge(Graph g,Vertex V,Vertex vAdj){
	int index1 = hash(V->url);
	int index2 = hash(vAdj->url);

	Vertex newV=createVertex(vAdj->url,vAdj->name);

	if(strcmp(g->arr[index2].url,"\0")==0){// if index2 is empty,adjV added and numV++
		strcpy(g->arr[index2].url,vAdj->url);
		strcpy(g->arr[index2].name,vAdj->name);
		g->numV++;
	}

	if(strcmp(g->arr[index1].url,"\0")==0){//if index1 is empty,v added there and numV++
		strcpy(g->arr[index1].url,V->url);
		strcpy(g->arr[index1].name,V->name);
		g->numV++;
	}


	Adjlist temp = &g->arr[index1];

	while(temp!=NULL){
		if(strcmp(temp->url,V->url)==0){// if v->url already exists
			newV->next = temp->head;
			temp->head = newV;
			break;
		}		
		temp = temp->next;
	}

	//else if v->url doesnt exist
	if(temp==NULL){
		temp = newAdjlistNode(V->url,V->name);
		temp->next = g->arr[index1].next;
		g->arr[index1].next = temp;
		temp->head = newV;//a new AdjListNode of v in index1 made 
		g->numV++;
	}

	temp = &g->arr[index2];

	while(temp!=NULL){
		if(strcmp(temp->url,vAdj->url)==0){//if vAdj->url already there
			break;
		}		
		temp = temp->next;
	}
	//else if vAdj->url doesnt exist
	if(temp ==NULL){
		temp = newAdjlistNode(vAdj->url,vAdj->name);
		temp->next = g->arr[index2].next;
		g->arr[index2].next = temp;
		g->numV++;
	}
	return g;
}

Adjlist newAdjlistNode(char *url,char *name){
	Adjlist newA = (Adjlist)malloc(sizeof(struct adjlist));
	strcpy(newA->url,url);
	strcpy(newA->name,name);
	newA->head =NULL;	
	newA->next =NULL;
	newA->visited = false;
	return newA;
}
