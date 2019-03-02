#include "header.h"
#include<sys/time.h>
void measureTS(FILE *fp,FILE *out,int *p){
	struct timeval t1,t2;
	double elapsedTime;
	
	gettimeofday(&t1,NULL);
	if(fp == NULL){
		printf("unable to open file");
	}
	Credit cre = createArr();
	CreditP cp = (CreditP) malloc(sizeof(struct CreditP));
	cp->c = cre;
	cp->Tcount =100;
	cp->Pcount =0;
	cp = storeDetails(cp,fp);
	gettimeofday(&t1,NULL);
	insertSort(cp->c,cp->Pcount,out,p);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000;
	printf("Elapsed time:%lf",elapsedTime);
	fprintf(out,"Time:%lf ",elapsedTime);
	fclose(fp);
	free(cp->c);
	return;
}
