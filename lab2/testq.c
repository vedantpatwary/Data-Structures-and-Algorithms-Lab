#include "multiq.h"
#include "que.h"

int main(void){
	Queue q = newQ();
	q->p = 1;
	Element e = newE(1);
	q = addQ(q,e);
	printQ(q);
	e = newE(2);
	q = addQ(q,e);
	printQ(q);
	e = newE(3);
	q = addQ(q,e);
	printQ(q);
	MultiQ mq = createMQ(10);
	Task t = {1,1};
	mq = addMQ(mq,t);
	printMultiQ(mq);
	return 0;
}

