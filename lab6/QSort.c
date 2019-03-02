#include "header.h"

void QuickSort(Employee e,int low,int high,int S){
	StackP sp = newStack(10000);
	struct stack s1 ;
	s1.low = low;
	s1.high = high;
	sp = push(sp,s1);
	int p=0;
	while(!isEmpty(sp)){
		s1 = top(sp);
		high = s1.high;
		low = s1.low;
		sp = pop(sp);
		while(low<high){
			p = pivot(e,low,high);
			p = partition(e,low,high,p);
			s1.low = low;
			s1.high = p-1;
			sp = push(sp,s1);
			low =p+1;
		}
	}
}
