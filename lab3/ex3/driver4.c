#include "header.h"
#include "cycle.h"
int count =0;
int main(void){
	List l = createList(10008760);
	l = createCycle(l);
	bool b = testCyclic(l);
	printf("count initial:%d\n",count);
	if(b==true)
		printf("cyclic !\n");
	else
		printf("Linear!\n");
	l = makeCircularList(l);
	printf("count final:%d\n",count);
}

