#include "header.h"
extern int count;
void* myalloc(int x){
	void *p = (void*)malloc(x+4);
	*(int*)p = x;
	count+=x;
	p = (int*)p +1;
	return (void*)p;
}


void myfree(void *p){
	p = (int*)p -1;
	int todel = *((int*)p);
	count-=todel;
	free(p);
}

void printAdd(int *p){
	printf("A[0]:%u\t",p);
	int num = *(--p);
	p = p+num/4;
	printf("A[%d]:%u\n",num/4-1,p);
}

List createList(int N){
	List LinkedList = NULL;
	List newList= NULL;
	List prevList= NULL;
	srand(time(0));
	int r;
	prevList = (List)myalloc((int)sizeof(struct list));
	LinkedList = prevList;
	r = rand();
	prevList->n = r;
	for(int i=0;i<N-1;i++){
		r = rand() % RAND_MAX+1 +  0;		
		newList = (List)myalloc((int)sizeof(struct list));
		newList->n = r;
		newList->next = NULL;
		prevList->next = newList;
		prevList = newList;
	}
	return LinkedList;
}

void printList(List l){
	printf("LinkedList is:");
	while(l!=NULL){
		printf("%d->",l->n);
		l =l->next;
	}
}

List createCycle(List l){
	srand(time(0));
	int t = rand() %2 + 0;
	List last = l;
	List LinkedList = l;
	if(t==1)
		printf("linear toss");
	else
		printf("Cyclic toss");
	if(t==HEAD){ // cyclic
		int r = rand() % RAND_MAX+1 + 0;
		while(l->n != r && l->next!=NULL){
			l = l->next;
			last = last->next;
		}
		while(last ->next != NULL)
			last = last->next;
		if(l -> n == r)
			last -> next = l;
	}
	else{
		return l;
	}
	return LinkedList;
}
