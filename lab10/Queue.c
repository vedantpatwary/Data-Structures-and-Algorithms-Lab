#include "Queue.h"

Queue createQ(void){
        Queue q = (Queue)malloc(sizeof(struct queue));
        q->head =NULL;
        q->tail =NULL;
        q->count =0;
        return q;
}

Queue enque(Queue q,Vertex v){
        Node n = (Node)malloc(sizeof(struct queue));
	n->v =v;
	n->next =NULL;
        if(q->count ==0){
                q->head =n;
                q->tail =n;
                q->count++;
        }
        else{
                q->tail->next =n;
                q->tail =n;
                q->count++;
        }
        return q;
}

Queue deque(Queue q){
        if(q->count ==0)
                return q;
        if(q->count ==1){
                Node temp = q->head;
                q->head =NULL;
                q->tail =NULL;
                q->count--;
                free(temp);
        }
        else{
                Node temp = q->head;
                q->head = temp->next;
                q->count--;
                free(temp);
        }
        return q;
}

Vertex front(Queue q){
	if(q->count ==0)
		return NULL;
	return q->head->v;
}

bool isEmptyQ(Queue q){
	if(q->count ==0)
		return true;
	return false;
}
