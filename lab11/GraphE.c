#include "GraphE.h"

Graph createGraph(FILE *fp){
	if(fp ==NULL)
		return NULL;
	
	Graph g = (Graph)malloc(sizeof(struct graph));
	int i =1;
	int num1,num2;
	while(fscanf(fp,"%d %d",&num1,&num2) ==2){
		if(i==1){
			g->listE =(Edge)malloc(sizeof(struct edge));
			g->listE[i-1].head = num1;
			g->listE[i-1].tail = num2;
			i++;
			continue;
		}

		g->listE =(Edge)realloc(g->listE,i*sizeof(struct edge));
		g->listE[i-1].head = num1;
		g->listE[i-1].tail = num2;
		i++;
	}
	g->numE = i-1;
	return g;
}
	
void printGraph(Graph g){
	for(int i=0;i<g->numE;i++){
		printf("%d->%d\n",g->listE[i].head,g->listE[i].tail);
	}
}	
