#include "tree.h"
#include "stack.h"

Stack createStack(void){
	Stack s =(Stack)malloc(sizeof(struct stack));
	s->index =-1;
	s->capacity = 1000;
	Tree *temp;
	for(int i=0;i<s->capacity;i++){
		s->arr[i] =NULL;
	}
	return s;
}

Stack push(Stack s,Tree t){
	s->index++;
	s->arr[s->index] = t;
	return s;
}

Stack pop(Stack s){
	if(s->index ==-1)
		return s;
	s->arr[s->index] =NULL;
	s->index--;
	return s;
}

Tree top(Stack s){
	if(s->index ==-1)
		return NULL;
	return s->arr[s->index];
}
	
bool isEmptyS(Stack s){
	if(s->index ==-1)
		return true;
	return false;
}
