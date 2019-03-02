#include "multiq.h"
#include "que.h"

/*Element newE(int x){
	Element e;
	e.key = x;
	return e;
}*/
void printQ(Queue q){
	node n = q->head;
	while(n!= NULL){
		printf("%d->",n->ele.tid);
		n = n->next;
	}
	printf("\n");
	return;
}
Queue newQ(){
	Queue q = (Queue)malloc(sizeof(Queue));
	q->head =NULL;
	q->tail =NULL;
	q->count = 0;
	return q;
}

bool isEmptyQ(Queue q){
	if(q ->count ==0)
		return true;
	return false;
}

Queue delQ(Queue q){
	node n = q->head;
	if(q->count ==0)
		return q;
	
	else if(q->count ==1){
		q->head =NULL;
		q->tail =NULL;
		q->count--;
	}
	
	else{
		q->head = n->next;
		q->count--;
	}
	free(n);
	return q;
}

Element front(Queue q){
	if(q->count == 0 ){
		Element e;
		return e;
	}
	return q->head->ele;
}	

Queue addQ(Queue q,Task e){
	node n = (node)malloc(sizeof(struct node));
	n->ele = e;
	n->next =NULL;
	if(q->count ==0){
		q->head =n;
		q->tail =n;
		q->count++;
	}
	else{
		q->tail->next =n;
		q->tail = n;
		q->count++;
	}
	return q;
}

int lengthQ(Queue q){
	return q->count;
}




