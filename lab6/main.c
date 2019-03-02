#include "header.h"

int main(void){
	FILE *fp =fopen("data.txt","r");
	Employee e = createArr(2000);
	int size =2000;
	readFile(e,fp);
	fclose(fp);
	QuickSort(e,0,size-1,0);
	printArr(e,size);
}
