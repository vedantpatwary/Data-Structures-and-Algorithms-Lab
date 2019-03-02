#include "adjLGraph.h"
#include "Queue.h"

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
		
void BFS(Graph g,Vertex v){
	Queue q = createQ();
	q = enque(q,v);
	Vertex tempV;
	Vertex tempV2;
	while(!isEmptyQ(q)){
		tempV = front(q);
		q = deque(q);
		int index = map(tempV->data);
		if(g->arr[index].visited == false){
			printf("%d ",tempV->data);
			g->arr[index].visited = true;
			tempV2 = getAdjacent(g,tempV);
			while(tempV2 !=NULL){
				q = enque(q,tempV2);
				tempV2 = tempV2->next;	
			}
		}
	}
}	
			
		
