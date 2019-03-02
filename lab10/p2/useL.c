#include "adjLGraph.h"
#include "Queue.h"

/*
void DFS(Graph g,Vertex V){
	printf("%d ",V->data);
	Vertex iter = getAdjacent(g,V);
	while(iter != NULL){
		int index = map(iter->data);
		if(g->arr[index].visited ==false){	
		//	printf("%d ",iter->data);
			g->arr[index].visited = true;
			DFS(g,iter);
		}
		iter = iter->next;
	}
	return;
}	
*/
		
void BFS(Graph g,Vertex v){
	Queue q = createQ();
	q = enque(q,v);
	Vertex tempV;
	Vertex tempV2;
	Adjlist tempA;
	while(!isEmptyQ(q)){
		tempV = front(q);
			
		printf("%s \n",tempV->url);
		q = deque(q);

		if(g->numV<200 ){
			int x =	curl(tempV->url);
			if(x==0)
				readFile(g,tempV->url,tempV->name);
		}
		int index = hash(tempV->url);
		tempA = &g->arr[index];

		while(tempA != NULL){
			if(strcmp(tempA->url,tempV->url)==0)
				break;
			tempA = tempA->next;
		}
		if(tempA==NULL)
			continue;

		if(tempA->visited == false){// enque it the bfs way
			tempA->visited = true;
			tempV2 = getAdjacent(g,tempV);
			while(tempV2 !=NULL){
				q = enque(q,tempV2);
				tempV2 = tempV2->next;	
			}
		}
	}
	printf("%d",g->numV);
}	
			
		
