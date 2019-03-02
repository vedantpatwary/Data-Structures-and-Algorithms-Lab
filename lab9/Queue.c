#include "iterLL.h"
#include "Queue.h"

Queue createQueue(){
	Queue q =(Queue)malloc(sizeof(struct queue));
	for(int i=0;i<100000000;i++){
		q->it[i] =NULL;
	}
	q->front =0;
	q->rear =0;
	q->count =0;
	q->sizeQueue = 100000000;
	return q;
}

Queue enque(Queue q,Iterator it){
	q->it[q->rear] = it;	
	q->rear = (q->rear+1)%q->sizeQueue;
	q->count++;
	return q;
}

Queue deque(Queue q){
	if(q->count ==0)
		return q;
	q->it[q->front] = NULL;
	q->count--;
	q->front = (q->front+1)%q->sizeQueue;
	return q;
}

Iterator front(Queue q){
	if(q->count ==0)
		return NULL;
	return q->it[q->front];
}

bool isEmptyQ(Queue q){
	if(q->count == 0)
		return true;
	return false;
}
	
