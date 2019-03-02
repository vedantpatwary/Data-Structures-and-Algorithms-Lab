#include "header.h"

void mergeSort(Student arr,int size,int *p,unsigned int *max){
	int maxSz = size;
	int st1 =0;
	int st2 =0;
	int sz2 =0;
	int sz1 =0;
	int temp=0;
	*max = (p-&sz1);
	for(int sz=1;sz<maxSz;sz*=2){
		for(st1=0;st1<maxSz;st1= st1+2*sz){
			st2 = st1+sz;
			sz1 =sz;
			sz2 =sz;
			if(st2>=maxSz){
				temp = st2;
				while(temp != maxSz){
					sz1--;
					temp--;
				}
				st2 = maxSz-1;
				sz2 =0;
			}
			else if(st2+sz >=maxSz){
				temp = st2+sz;
				while(temp != maxSz){
					sz2--;
					temp--;
				}
			}
			Student newArr = (Student)malloc(sizeof(struct student)*(sz2+sz1));
			merge(arr+st1,sz1,arr+st2,sz2,newArr);
			free(newArr);
		}
	}
}



