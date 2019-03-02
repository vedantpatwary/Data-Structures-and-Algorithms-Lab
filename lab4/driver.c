#include "header.h"
#include <sys/time.h>

int main(void){
	struct timeval t1,t2;
	double elapsedTime;

	gettimeofday(&t1,NULL);
	
	FILE *fp = fopen("100000","r");
	if(fp == NULL){
		printf("unable to open file");
		return 0;
	}
	Credit cre = createArr();
	CreditP cp = (CreditP) malloc(sizeof(struct CreditP));
	cp->c = cre;
	cp->Tcount =100;
	cp->Pcount =0;
	cp = storeDetails(cp,fp);
	fclose(fp);
	fp = fopen("100000","r");
	cp = storeDetails(cp,fp);
	printDetails(cp);
	printf("Tcount:%d",cp->Tcount);
	printf("Pcount:%d",cp->Pcount);
	fclose(fp);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000;
	printf("Time:%lf",elapsedTime);
	fp = fopen("Output.txt","w");
	fprintf(fp,"%lf",elapsedTime);
}

