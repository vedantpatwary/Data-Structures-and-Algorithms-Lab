#include "iterArr.h"
#include "treeArr.h"

bool hasMoreElements(Iterator it){
	if(it->size ==0)
		return false;
	if(it->cur<=it->size-1)
		return true;
	return false;
}

Element getNextElement(Iterator it){
	int cur = it->cur;
	it->cur++;
	Tree temp = it->head+cur;
	return temp;
}
