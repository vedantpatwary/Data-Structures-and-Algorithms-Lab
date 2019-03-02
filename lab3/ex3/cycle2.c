#include "header.h"
#include "cycle.h"

bool testCyclic(List l){
	List p =l;
	List n = l->next;
	List nn = n->next;
	if( p ==NULL || n ==NULL)
		return false;
	while(nn != NULL){
		nn = n->next;;
		n->next =p;
		p =n;
		n = nn;
		if(nn == l)
			return true;
	}
	return false;	
}		
	
