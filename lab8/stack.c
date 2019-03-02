#include"tree.h"
#include "stack.h"

Stack createStack(void){
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->head =NULL;
	s->tail =NULL;
	s->count =0;
}

Stack push(Stack s,Tree bt){
	Node n = (Node)malloc(sizeof(struct node));
	n->bt = bt;
	n->next =NULL;
	if(isEmptyS(s)){
		s->head = n;
		s->tail =n;
		s->count++;
	}
	else{
		n->next = s->head;
		s->head = n;
		s->count++;
	}
	return s;
}
		

Stack pop(Stack s){
	if(isEmptyS(s))
		return s;
	else{
		if(s->count ==1){
			free(s->head);
			s->head = NULL;
			s->tail =NULL;
			s->count--;
			return s;
		}
		Node temp = s->head;
		s->head = temp->next;
		free(temp);
		s->count--;
	}
	return s;
}

Tree top(Stack s){
	if(isEmptyS(s))
		return NULL;
	else
		return s->tail->bt;
}

bool isEmptyS(Stack s){
	if(s->count ==0)
		return true;
	return false;
}
