#include "multiq.h"
#include "que.h"

int main(void){
	printf("%lu",sizeof(node)*2 + sizeof(int)*2);
	printf("%lu",sizeof(struct q));
	Queue q = newQ();
	q->p = 1;
	Element e1 = newT(1,2);
	q = addQ(q,e1);
	printQ(q);
	Element e2 = newT(3,5);
	q = addQ(q,e2);
	printQ(q);
	Element e3 = newT(5,1);
	q = addQ(q,e3);
	printQ(q);
	MultiQ mq = createMQ(10);
	Element e4 = newT(6,3);
	Element e5 = newT(6,5);
	printMultiQ(mq);
	FILE *fp = fopen("input10000.txt","r");
	if(fp ==NULL){
		printf("NULL FILEP");
		return 0;
	}
	Element e ={0,0};
	char c;
	while(fscanf(fp,"%d,%d",&e.tid,&e.p) == 2){
		mq = addMQ(mq,e);
	}
	printMultiQ(mq);
	printf("\n size:%d\n",sizeMQ(mq));
	fclose(fp);
	return 0;
}

