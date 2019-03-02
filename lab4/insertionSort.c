#include "header.h"

void insertInOrder(Credit c,int n,struct credit nc){
	if(n>=1){
		if(nc.card_no<c[n-1].card_no){
			c[n] = c[n-1];
			c[n-1] = nc;
			insertInOrder(c,n-1,c[n-1]);
		}
	}
	else{
		c[n] = nc;
		return;
	}
}


void insertSort(Credit c,int n,FILE *out,int *p){
	if(n>1){
		insertSort(c,n-1,out,p);
		insertInOrder(c,n-1,c[n-1]);
	}
	else{
		int x=0;
		printf("yes");
		fprintf(out,"Stack:%lu\n",p-&x);
		return;
	}
}
