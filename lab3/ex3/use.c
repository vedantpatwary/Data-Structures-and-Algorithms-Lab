#include "header.h"
#include "cycle.h"

List makeCircularList(List l){
	bool b = testCyclic(l);
	if(b== false){
		List last = l;
		while(last -> next !=NULL)
			last = last->next;
		last->next =l;
		return l;
	}
	
	List hare =l;
	List tort = l;
	hare = hare->next->next;
	tort = tort -> next;
	while(hare != tort){
		hare = hare->next->next;
		tort = tort ->next;
	}
	int c =0;
	tort = tort->next;
	c++;
	while(hare != tort){
		tort = tort->next;
		c++;
	}
	hare = l;
	tort = l;
	while(c != 0){
		hare = hare->next;
		c--;
	}
	while(hare != tort){
		hare = hare->next;
		tort = tort ->next;
	}
	List nextl = l->next;
	while(l!= hare){
		l = nextl;
		nextl = nextl->next;
		myfree(l);
	}
	return l;
}	
