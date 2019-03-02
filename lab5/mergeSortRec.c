#include "header.h"

void mergeSort(Student arr,int size,int *p,unsigned int *max){
	
	if(size>1){
		int sz1=size/2;
		int sz2=size-sz1;
		if(*max<(p-&sz1))
			*max = p - &sz1;
		mergeSort(arr,sz1,p,max);
		mergeSort(arr+sz1,sz2,p,max);
		Student newArr = (Student)malloc(sizeof(struct student)*(sz1+sz2));
		merge(arr,sz1,arr+sz1,sz2,newArr);
		free(newArr);
	}
	else{
		return;
	}
}

