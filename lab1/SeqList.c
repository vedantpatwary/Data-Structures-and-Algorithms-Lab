#include "SeqList.h"

int main(void){
	SeqList sl = newList();
	sl=insertAtFront(sl,5);
	printList(sl);
	sl=insertAtEnd(sl,21);
	printList(sl);
	sl=insertInOrder(sl,18);
	sl=insertInOrder(sl,2);
	sl=insertInOrder(sl,40);
	printList(sl);
	sl=deleted(sl,2);
	printList(sl);
        sl=deleted(sl,40);
	printList(sl);
	sl=deleteAtFront(sl);
	printList(sl);
	return 0;
}
SeqList newList(void){
	SeqList sl = (SeqList*)malloc(sizeof(SeqList));
	sl->head=NULL;
	sl->tail=NULL;
	sl->count=0;
	return sl;
}

void printList(SeqList sl){
	printf("inside printList\n");
	if(sl == NULL){
		printf("List is null");
		return;
	}
	SeqList p = sl;
	while(p!=NULL){
		printf("%d\n",p->e);
		p=p->next;
	}
	return ;
}
SeqList insertAtFront(SeqList sl,Element e){
	if(sl !=NULL){
		e->next = head;
		sl->head = e;
		sl->count++;
		return sl;
	
	}
	else{
		SeqList newSl = newList();
		newSl->head = e;
		newSl->tail = e;
		e->next =NULL;
		newSl->count++;
		return newSl;
	}	
}

SeqList insertAtEnd(SeqList sl,Element e){
	if(sl==NULL){
		SeqList newSl = newList();
		newSl->head = e;
		newSl->tail = e;
		e->next =NULL;
		newSl->count++;
		return newSl;
		return newSL;
	}	
	sl->tail->next=e;
	sl->tail=e;
	sl->count++;
	return sl;
}

SeqList deleted(SeqList sl,Element e){
	if(sl==NULL){
		printf("null list:nothing to delete");
		return sl;
	}	
	if(sl->head==e){
		free(sl);	
		return sl;
	}SeqList prev = sl;
	SeqList n =sl->next;
	int flag=0;
	while(n !=NULL){
		if(n->e ==e){
			prev->next=n->next;
			free(n);			
			flag=1;	
		}
		prev=prev->next;
		n = n->next;		
	}
	if(flag==0)
		printf("Element not found");	
	return sl;
}

SeqList deleteAtFront(SeqList sl){
	if(sl==NULL){
		printf("Null list:nothing to delete");
		return sl;
	}
	SeqList p =sl;
	sl = sl->next;
	free(p);
	return sl;
}

Element find(SeqList sl,Key k){
	if(sl==NULL)
		return 0;	
	SeqList p = sl;
	while(p!=NULL){
		if(p->e ==k){
			return p->e;
		}
	}
	printf("could not find key %d in list",k); 
	return 0;
}

SeqList insertInOrder(SeqList sl, Element e){
	if(sl==NULL){
		SeqList newsl = (SeqList)malloc(sizeof(SeqList));
		newsl->e =e;
		newsl->next=NULL;
		return newsl;
	}		
	SeqList prev = sl;
	SeqList newsl = (SeqList)malloc(sizeof(SeqList));
	newsl->e=e;
	SeqList n = sl->next;
	if(newsl->e < sl->e){
		newsl->next = sl;
		sl = newsl;
		return sl;
	}
	while(n!=NULL){
		if((newsl->e)>prev->e&& newsl->e < n->e){
			newsl->next =n;
			prev->next = newsl;
			return sl;
		}
		prev=prev->next;
		n=n->next;
	}
	prev->next = newsl;
	newsl->next =NULL;
	return sl;
}
