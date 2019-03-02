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

