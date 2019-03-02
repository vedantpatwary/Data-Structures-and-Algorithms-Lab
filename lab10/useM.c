#include "adjMGraph.h"
#include "Queue.h"

void DFS(Graph g,Vertex v){
		printf("%d ",v->data);
		Enumeration tempE = getAdjacent(g,v);
		Vertex temp = NULL;
		while(tempE != NULL){
			temp = tempE->v;
			if(temp->visited ==false){
				temp->visited = true;
				DFS(g,temp);
			}
			tempE = tempE->next;
		}
}
	
void BFS(Graph g,Vertex v){
        Queue q = createQ();
        q = enque(q,v);
        Vertex tempV;
        Vertex tempV2;
	Enumeration tempE;
        while(!isEmptyQ(q)){
                tempV = front(q);
                q = deque(q);
                int index = map(tempV->data);
                if(g->listV[index].visited == false){
                        printf("%d ",tempV->data);
                        g->listV[index].visited = true;
                        tempE = getAdjacent(g,tempV);
                        while(tempE !=NULL){
				tempV2 = tempE->v;
                                q = enque(q,tempV2);
                                tempE = tempE->next;
                        }
                }
        }
}


