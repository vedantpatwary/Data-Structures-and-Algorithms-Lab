#include "header.h"
#include "cycle.h"
bool testCyclic(List l){
	List hare = l;
	List tort = l;
	hare = hare->next;
	if(hare ==NULL) return false;
	hare = hare->next;
	tort = tort->next;
	while(hare !=NULL){
		if(hare == tort || hare->next == tort)
			return true;
		tort = tort->next;

		hare = hare->next;
		if(hare == NULL)
			return false;
		hare = hare->next;
	}
		return false;
}
