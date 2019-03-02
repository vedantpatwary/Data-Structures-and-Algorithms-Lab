#include "header.h"
int count =0;
int main(void){
	List l = createList(1000000);
	printList(l);
	FILE *fp = fopen("output.txt","w");
	fprintf(fp,"%d",count);
	fclose(fp);
	printf("\n\n\n\n");
	l = createCycle(l);
	printList(l);
}

