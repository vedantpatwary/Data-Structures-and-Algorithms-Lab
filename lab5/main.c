#include "header.h"

int main(void){
	int size = 1024;

	FILE *fp = fopen("1024.txt","r");
	size = 1024;
	doEvery(fp,size);
	fp = fopen("10240.txt","r");
	size = 10240;
	doEvery(fp,size);
	fp = fopen("102400.txt","r");
	size = 102400;
	doEvery(fp,size);
}

void doEvery(FILE *fp,int size){
	struct timeval t1,t2;
	double elapsedTime;
	printf("%d:",size);
	Student arr = allocArray(size);
	arr = readFile(fp,arr);
	fclose(fp);
	int max=0;
	gettimeofday(&t1,NULL);
	mergeSort(arr,size,&size,&max);
	printf("Stack:%u",max);
	gettimeofday(&t2,NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000000000000000;
	printf(" Time:%lf\n",elapsedTime);
	printf("\n");
}	
