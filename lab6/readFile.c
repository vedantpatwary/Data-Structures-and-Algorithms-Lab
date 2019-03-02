#include "header.h"

Employee createArr(int size){
	Employee e = (Employee)malloc(sizeof(struct emp)*size);
	return e;
}

void readFile(Employee e,FILE *fp){
	int i=0;
	while((fscanf(fp,"%s %ld",e[i].name,&e[i].empID)==2)){
		i++;
	}	
}
	
void printArr(Employee e,int size){
	for(int i=0;i<size;i++){
		printf("%s,%ld\n",e[i].name,e[i].empID);
	}
}
