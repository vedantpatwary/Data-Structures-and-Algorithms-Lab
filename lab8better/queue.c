#include "tree.h"
#include "queue.h"

Queue createQueue(void){
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->head =NULL;
	q->tail =NULL;
	q->count =0;
	return q;
}

Queue enque(Queue q,Tree t){
	Node n = (Node)malloc(sizeof(struct node));
	n->t = t;
	n->next =NULL;
	if(q->count ==0){
		q->head = n;
		q->tail =n;
		q->count++;
		return q;
	}
	q->tail->next = n;
	q->tail =n;
	q->count++;
	return q;
}

Queue deque(Queue q){
	if(q->count ==0)
		return q;
	Node temp =NULL;
	if(q->count ==1){
		temp = q->head;
		q->head  =NULL;
		q->tail =NULL;
	}
	else{
		temp = q->head;
		q->head = temp->next;
	}
	q->count--;
	free(temp);
	return q;
}

Tree front(Queue q){
	if(q->count ==0)
		return NULL;
	return q->head->t;
}

bool isEmptyQ(Queue q){
	if(q->count ==0)
		return true;
	return false;
}
