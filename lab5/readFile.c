#include "header.h"
Student readFile(FILE *fp,Student arr){
	int i=0;
	if(fp==NULL){
		return NULL;
	}
	while(fscanf(stdin,"%[a-z],%f\n",arr[i].name,&arr[i].cgpa) == 2){
		i++;
	}
	return arr;
}

void printArr(Student arr,int size){
	for(int i=0;i<size;i++){
		printf("Student:%d:",i);
		printf("%s\n",arr[i].name);
		printf("%f\n",arr[i].cgpa);
	}
}

Student allocArray(int size){
	Student arr = (Student)malloc(size*sizeof(struct student));	
	return arr;
}

