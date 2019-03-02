#include "header.h"
int main(void){
	srand(time(0));
	for(int i=0;i<50;i++){
		int r = rand() % 15001 + 10000;
		printf("randno:%d\n",r);
		printf("floated/4 :%f",(float)r/4);
		int *x = (int*)myalloc(r);
		printAdd(x);
		printf("count :%d\n",count);

		myfree(x);

		printf("count :%d\n\n",count);
	}
}

