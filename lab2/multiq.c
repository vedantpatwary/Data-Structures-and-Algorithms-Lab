#include "multiq.h"
#include "que.h"

MultiQ createMQ(int num){
	Queue q = (Queue)malloc(sizeof(struct q)*num);
	MultiQ mq = (MultiQ)malloc(sizeof(struct multiq));
	mq->q =q;
	mq->size =num;
	for(int i=0;i<num;i++){
		q->head =NULL;
		q->count =0;
		q->tail = NULL;
		q->p =i+1;
		q++;
	}
	return mq;
}

MultiQ addMQ(MultiQ mq,Task t){
	if(mq->q == NULL)
		printf("it is the fault");
	Queue q = mq->q;
	while(q->p != t.p)
		q++;
	q = addQ(q,t);
	return mq;
}

Task nextMQ(MultiQ mq){
	Queue q = mq->q;
	q+= mq->size-1;
	while(q->count == 0&& q!= NULL){
		q--;
	}
	if(q==NULL){
		Task t;
		t.p =0;
		t.tid =0;
		return t;
	}
	return q->head->ele;
}

MultiQ delNextMQ(MultiQ mq){
	Queue q = mq->q;
	q+= mq->size-1;
	while(q->count == 0&& q!= mq->q){
		q--;
	}
	if(q==mq->q&& q->count ==0)
		return mq;
	q = delQ(q);
	return mq;
}

bool isEmptyMQ(MultiQ mq){
	Queue q = mq->q;
	int i=0;
	while(i < mq->size){
		if(q->count >0)
			return false;
		i++;
		q++;
	}
	return true;
}

int sizeMQ(MultiQ mq){
	Queue q = mq->q;
	int sum=0;
	int i=0;
	while(i<mq->size){
		sum+=q->count;
		i++;
		q++;
	}
	return sum;
}

int sizeMQbyPriority(MultiQ mq,Priority p){
	Queue q = mq->q;
	return q[p-1].count;
}

Queue getQueueFromMQ(MultiQ mq,Priority p){
	Queue q = mq->q;
	q+=p-1;
	return q;
}

void printMultiQ(MultiQ mq){
	int i=0;
	Queue q =mq ->q;
	for(i =0;i<mq->size;i++){
		printf("Queue%d:",i+1);
		printQ(q);
		q++;
	}
}

Task newT(Priority p,int tid){
	Task t;
	t.tid = tid;
	t.p =p;
	return t;
}


