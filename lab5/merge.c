#include "header.h"

void merge(Student arr1,int sz1,Student arr2,int sz2,Student arr){
	int i=0;
	int j=0;
	int k=0;
	while(i<sz1 && j<sz2){
		if((arr1[i].cgpa) <= (arr2[j].cgpa)){
			arr[k] = arr1[i];
			i++;
		}
		else{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while(i<sz1){
		arr[k] = arr1[i];
		i++;
		k++;
	}
	while(j<sz2){
		arr[k] = arr2[j];
		j++;
		k++;
	}
	k=0;
	arr1 = memcpy((Student)arr1,(Student)arr,sizeof(struct student)*sz1);
	if(sz2!=0)
		arr2 = memcpy((Student)arr2,(Student)(arr+sz1),sizeof(struct student)*sz2);
}	


