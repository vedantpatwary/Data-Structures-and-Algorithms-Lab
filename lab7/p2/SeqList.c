#include "SeqList.h"
#include "header.h"

SeqList newList(void){
	SeqList sl = (SeqList)malloc(sizeof(struct seqList));
	sl->head=NULL;
	sl->tail=NULL;
	sl->count=0;
	return sl;
}

void printList(SeqList sl,char **Book){
	//printf("inside printList\n");
	if(sl == NULL){
	//	printf("List is null");
		return;
	}
	Element p = sl->head;
	while(p!=NULL){
		printf("%s ",Book[p->index]);
		printf("%d \n             ",p->count);
		p=p->next;
	}
	return ;
}
SeqList insertAtFront(SeqList sl,Element e){
	if(sl !=NULL){
		e->next = sl->head;
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
	}	
	if(sl->count ==0){
		sl->head = e;
		sl->tail =e;
		sl->count =1;
		return sl;
	}
	sl->tail->next=e;
	sl->tail=e;
	sl->count++;
	return sl;
}
int insertAtEndCost(SeqList sl,Element e,int insertionCost){
	if(sl==NULL){
		SeqList newSl = newList();
		newSl->head = e;
		newSl->tail = e;
		insertionCost++;
		e->next =NULL;
		newSl->count++;
		return insertionCost;
	}	
	if(sl->count ==0){
		sl->head = e;
		sl->tail =e;
		sl->count =1;
		insertionCost++;
		return insertionCost;
	}
	Element el =sl->head;
	while(el->next!=NULL){
		insertionCost++;
		el= el->next;	
	}
	el->next = e;
	insertionCost++;
	return insertionCost;
}

void deleted(SeqList sl,Element e){
	SeqList temp = sl;
	if(sl==NULL){
		printf("null list:nothing to delete");
		return ;
	}	
	if(sl->count ==0)
		return;
	if(sl->head->index==e->index){
		Element et = e;
		free(e);	
		sl->head =et;
		return ;
	}
	Element prev = sl->head;
	Element n =prev->next;
	int flag=0;
	while(n !=NULL){
		if(n->index ==e->index){
			prev->next=n->next;
			temp->count-=n->count;
			free(n);			
			flag=1;	
		}
		prev=prev->next;
		n = n->next;		
	}
	if(flag==0)
		printf("Element not found");	
	return ;
}
/*
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
*/
Element find(SeqList sl,char **Book,Key k){
	if(sl==NULL)
		return NULL;	
	Element p = sl->head;
	while(p!=NULL){
		if(strcmp(Book[p->index],Book[k])==0){
			return p;
		}
		p = p->next;
	}
	return 0;
}
/*
SeqList insertInOrder(SeqList sl, Element e){
	if(sl==NULL){
		SeqList newsl = (SeqList)malloc(sizeof(SeqList));
		newsl->head =e;
		newsl->tail = e;
		newsl->count++;
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
*/
Element newElement(int index){
	Element newE = (Element)malloc(sizeof(struct element));	
	newE->index = index;
	newE->count = 1;
	newE->next =NULL;
	return newE;
}
	
Element findString(SeqList sl,char **Book,char **strings,Key k){
	if(sl==NULL)
		return NULL;	
	Element p = sl->head;
	while(p!=NULL){
		if(strcmp(Book[p->index],strings[k])==0){
			return p;
		}
		p = p->next;
	}
	return 0;
}
