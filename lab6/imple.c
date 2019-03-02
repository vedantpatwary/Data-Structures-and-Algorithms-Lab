#include "header.h"

StackP newStack(int size){
	StackP sp = (StackP)malloc(sizeof(struct stackp));
	Stack s = (Stack)malloc(sizeof(struct stack)*size);
	sp->sz=0;
	sp->s = s;
	return sp;
}

StackP push(StackP sp,struct stack s1){
	Stack s = sp->s;
	s[sp->sz] = s1;
	sp->sz++;
	return sp;
}

StackP pop(StackP sp){
	if(sp->sz==0){
		return sp;
	}
	Stack s = sp->s;
	sp->sz--;
	s[sp->sz].low =0;
	s[sp->sz].high =0;
	return sp;
}

struct stack top(StackP sp){
	if(sp->sz !=0){
		Stack s = sp->s;
		return s[(sp->sz)-1];
	}
	struct stack s1;
	s1.low =0;
	s1.high =0;
	return s1;
}	

bool isEmpty(StackP sp){
	if(sp->sz ==0)
		return true;
	return false;
}

int partition(Employee e,int low,int high,int p){
	swap(e+p,e+low);
	int lt =low+1;
	int rt = high;
	while(1){
		for(;lt<high && e[lt].empID<=e[low].empID;lt++);
		for(;e[rt].empID>e[low].empID&&rt>low;rt--);
		if(lt>=rt)
		{
			swap(e+low,e+rt);
			return rt;
		}
		if(lt<rt){
			swap(e+lt,e+rt);
			lt++;
			rt--;
		}
	}
	//int ppos = rt;
	//swap(e+low,e+ppos);
	//return ppos;	
}

void swap(Employee e1,Employee e2){
	struct emp temp = *e2;
	*e2 = *e1;
	*e1 = temp;
}

int pivot(Employee e,int low,int high){
	return high;
}
