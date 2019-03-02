#include "tree.h"
#include "ll.h"

List addL(List l,int data){
	if(l==NULL){
		 l = (List)malloc(sizeof(struct list));
		l->data = data;
		l->next =NULL;
		return l;
	}
	
	List temp = (List)malloc(sizeof(struct list));
	temp->data = data;
	temp->next = l->next;
	l->next = temp;
	return l;
}

void printL(List l){
	if(l==NULL)
		return;

	List temp = l;
	while(temp !=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	return;
}
